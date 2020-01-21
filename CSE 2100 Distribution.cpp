#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h> 
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
class student
{
    public:
        float cgpa;
        int roll;
        student(int r, float c)
        {
            roll = r;
            cgpa = c;
        }
};
vector< student > students;
void initCgpaData();
bool comparer(student i, student j)
{
    return i.cgpa > j.cgpa;
}
int main() 
{ 
    string teachers[] = {
        "NIM"
        , "MRI"
        , "BA"
        , "MAM"
        , "MSS"
        , "MJK"
        , "AMH"
        , "MAH"
        , "RT"
        , "BP"
        , "SA"
        , "EKH"
        , "SZM"
        , "AS"
        , "BS"
        , "MKP"
        , "MAR"
        , "SSG"
        , "BZI"
        , "NS"
        , "SVN"
        , "MZI"
        , "MFF"
        , "MH"
    };
    initCgpaData();
    sort(students.begin(),students.end(),comparer);
    
    map<string, vector<int> > output;
    for(int i=0; i< 6*24; i++)
    {
        output[teachers[i%24]].push_back(students[i].roll);
    }
    for(int i=6*24; i< 6*24+15; i++)
    {
        output[teachers[i%15]].push_back(students[i].roll);
    }


    for(int i=6*24+15; i< 6*24+15+8; i++)
    {
        output[teachers[i%8]].push_back(students[i].roll);
    }

    for(int i=6*24+15+8; i< students.size()-5; i++)
    {
        output[teachers[i%7]].push_back(students[i].roll);
    }

    for(int i=students.size()-5; i< students.size(); i++)
    {
        output[teachers[i%5]].push_back(students[i].roll);
    }

    output["MJK"].push_back(1603023);
    for(int i =0; i < 24; i++)
    {
        int len = output[teachers[i]].size();
        cout<<teachers[i]<<"\t"<<len<<" ";
        for(int j = 0; j< len ; j++)
        {
            cout<<output[teachers[i]][j]<<" ";
        }
        cout<<endl;
    }

	return 0; 
} 
void initCgpaData()
{

    float cgpa[200] =
    {
        0.00,
        3.84,
        3.22,
        3.29,
        3.73,
        3.04,
        3.60,
        3.47,
        3.64,
        2.66,
        2.95,
        3.03,
        3.10,
        3.26,
        3.56,
        3.60,
        2.59,
        2.88,
        3.56,
        2.95,
        3.54,
        3.42,
        3.60,
        0.00,
        2.92,
        2.94,
        2.86,
        3.36,
        3.46,
        2.96,
        3.08,
        2.88,
        3.03,
        3.17,
        3.45,
        3.39,
        3.07,
        3.23,
        3.73,
        2.66,
        3.06,
        3.06,
        2.91,
        3.20,
        3.28,
        2.98,
        3.33,
        2.91,
        3.60,
        3.47,
        3.46,
        2.94,
        3.24,
        3.31,
        3.01,
        3.11,
        2.96,
        2.90,
        0.00,
        2.87,
        3.16,
        3.88,
        3.55,
        3.42,
        3.51,
        3.49,
        3.18,
        3.52,
        3.01,
        3.62,
        3.23,
        3.46,
        3.63,
        3.54,
        3.47,
        3.55,
        2.67,
        3.52,
        3.41,
        3.04,
        3.48,
        3.48,
        2.91,
        3.07,
        3.38,
        3.28,
        3.66,
        2.79,
        3.14,
        3.61,
        3.50,
        3.71,
        2.97,
        3.04,
        3.04,
        3.34,
        3.72,
        3.10,
        2.76,
        2.76,
        3.05,
        3.16,
        2.94,
        3.41,
        3.13,
        3.40,
        3.02,
        3.08,
        3.67,
        3.39,
        3.54,
        3.26,
        2.94,
        3.13,
        2.58,
        2.97,
        3.24,
        3.80,
        3.13,
        2.78,
        3.27,
        3.49,
        2.97,
        3.12,
        3.57,
        2.86,
        3.21,
        3.06,
        3.70,
        3.48,
        2.63,
        2.98,
        3.22,
        3.63,
        2.86,
        2.63,
        2.80,
        2.77,
        2.68,
        3.63,
        2.97,
        3.28,
        3.05,
        3.21,
        2.66,
        3.03,
        2.68,
        3.47,
        3.25,
        3.44,
        3.59,
        2.96,
        3.63,
        3.20,
        2.90,
        2.66,
        3.17,
        2.74,
        3.23,
        3.79,
        2.65,
        2.99,
        3.12,
        2.85,
        2.53,
        3.14,
        3.56,
        3.25,
        2.79,
        2.54,
        3.79,
        3.00,
        3.52,
        3.41,
        2.49,
        3.56,
        2.88,
        2.99,
        3.41,
        2.93,
        2.93
    };
    for(int i =1; i <181;i++)
    {
        if(i==23 || i==58) continue;
        student temp(1803000+i, cgpa[i]);
        students.push_back(temp);
    }
    
}