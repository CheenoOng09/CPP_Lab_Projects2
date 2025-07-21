#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<string, double> AreaMacroMap;
typedef map<string, int> CountMacroMap;
typedef map<string, string> InstanceMacroMap;
typedef set<string> StringSet;

void readXFileMacro(fstream &xFile, AreaMacroMap &LEFMap, CountMacroMap &countMap);
void readB17FileInstance(fstream &b17File, InstanceMacroMap &DEFMap, AreaMacroMap &LEFMap);

int main()
{
    string LEFFile, DEFFile;
    cout << " LEF file name: ";
    cin >> LEFFile;
    cout << " DEF file name: ";
    cin >> DEFFile;
    time_t startTime = time(NULL);

    fstream inputFile;
    inputFile.open(LEFFile, ios_base::in);
    if (!inputFile)
    {
        cout << "Failed to open LEFFile\n";
        return 0;
    }

    // Read
    AreaMacroMap LEFMap;
    CountMacroMap countMap;
    readXFileMacro(inputFile, LEFMap, countMap);
    InstanceMacroMap DEFMap;
    inputFile.close();
    inputFile.open(DEFFile, ios_base::in);
    if (!inputFile)
    {
        cout << "Failed to open DEFFile\n";
        return 0;
    }
    readB17FileInstance(inputFile, DEFMap, LEFMap);

    set<string> blockedMacro;
    blockedMacro.insert("FILLER_75t");
    blockedMacro.insert("FILLER_xp5_75t");
    blockedMacro.insert("TAPCELL_WITH_FILLER_75t");
    blockedMacro.insert("TAPCELL_75t");
    blockedMacro.insert("DECAP_x10_75t");
    blockedMacro.insert("DECAP_x1_75t");
    blockedMacro.insert("DECAP_x2_75t");
    blockedMacro.insert("DECAP_x4_75t");
    blockedMacro.insert("DECAP_x6_75t");
    blockedMacro.insert("TIEHI_x1_75t");
    blockedMacro.insert("TIELO_x1_75t");

    // 10 frequent macro
    for (InstanceMacroMap::const_iterator it = DEFMap.begin();
        it != DEFMap.end(); ++it)
    {
        if (blockedMacro.find(it->second) != blockedMacro.end())
        {
            continue;
        }
        ++countMap[it->second];
    }
    vector<pair<int, string>> descendCount;
    for (CountMacroMap::const_iterator it = countMap.begin();
        it != countMap.end(); ++it)
    {
        descendCount.push_back(pair<int, string>(it->second, it->first));
    }
    sort(descendCount.begin(), descendCount.end(), greater<pair<int, string>>());

    // Instance count
    int insCount = DEFMap.size();

    // Macro count
    int macroCount = LEFMap.size();

    // Area
    double totalArea = 0.0;
    for (InstanceMacroMap::const_iterator it = DEFMap.begin();
        it != DEFMap.end(); ++it)
    {
        if (blockedMacro.find(it->second) != blockedMacro.end())
        {
            continue;
        }
        totalArea += LEFMap[it->second];
    }

    // Sorted vector
    vector<string> sortedDEF;
    for (InstanceMacroMap::const_iterator it = DEFMap.begin();
        it != DEFMap.end(); ++it)
    {
        sortedDEF.push_back(it->first);
    }

    // Output
    cout << " Number of cell instances: " << insCount << "   Number of macros: " << macroCount << '\n';
    cout << " Total Area: " << totalArea << '\n';
    cout << " The top 10 frequently used macros:\n";
    for (int i = 0; i < 10; ++i)
    {
        cout << setw(18) << descendCount[i].second << " " << descendCount[i].first << '\n';
    }
    cout << "\nInstances at locations 100, 500, 1000, 8000, 15000, and 20000 respectively:\n";
    cout << setw(7) << "100: " << sortedDEF[100] << '\n';
    cout << setw(7) << "500: " << sortedDEF[500] << '\n';
    cout << setw(7) << "1000: " << sortedDEF[1000] << '\n';
    cout << setw(7) << "8000: " << sortedDEF[8000] << '\n';
    cout << setw(7) << "15000: " << sortedDEF[15000] << '\n';
    cout << setw(7) << "20000: " << sortedDEF[20000] << '\n';

    time_t stopTime = time(NULL);
    cout << "\n Runtime: " << stopTime - startTime << endl;
    return 0;
}

void readXFileMacro(fstream &xFile, AreaMacroMap &LEFMap, CountMacroMap &countMap)
{
    xFile.clear();
    xFile.seekg(0);
    string tempStr;
    while (!xFile.eof())
    {
        xFile >> tempStr;
        if (tempStr == "MACRO")
        {
            string macroName;
            xFile >> macroName;
            double area = 0;
            for (;;)
            {
                xFile >> tempStr;
                if (tempStr == "SIZE")
                {
                    xFile >> area >> tempStr >> tempStr;
                    area *= stod(tempStr);
                    LEFMap.insert(AreaMacroMap::value_type(macroName, area));
                    countMap.insert(CountMacroMap::value_type(macroName, 0));
                    break;
                }
            }
        }
    }
}

void readB17FileInstance(fstream &b17File, InstanceMacroMap &DEFMap, AreaMacroMap &LEFMap)
{
    b17File.clear();
    b17File.seekg(0);
    string tempStr1, tempStr2;
    while (!b17File.eof())
    {
        b17File >> tempStr1;
        if (tempStr1 == "COMPONENTS")
        {
            for (;;)
            {
                b17File >> tempStr1;
                if (tempStr1 == "-")
                {
                    b17File >> tempStr1 >> tempStr2;
                    DEFMap.insert(InstanceMacroMap::value_type(tempStr1, tempStr2));
                }
                else if (tempStr1 == "END")
                {
                    break;
                }
            }
            break;
        }
    }
}
