#include<iostream>
#include<cstdio>
#include<string>
#include<climits>
#include<map>
using namespace std;

const int UNKNOWN_MAX_WEIGHT=-1;


struct City{
	string name;
	map<string,int>edges;
	int maxWeight;
	bool isVisit;
};


int findMaxWeight(map<string,City>roadMap,const string sourceName,const string targetName)
{
	City*currentCity=&(roadMap[sourceName]);
	currentCity->maxWeight=INT_MAX;
	
	do
	{
		currentCity->isVisit=true;
		City*nextCity=NULL;
		
		for(map<string,City>::iterator it=roadMap.begin();it!=roadMap.end();it++)
		{
			City*city=&(it->second); 
			if(currentCity->edges.find(city->name)!=currentCity->edges.end())
			{
				int edgeMaxWeight=currentCity->edges[city->name];
				int maxWeight=min(currentCity->maxWeight,edgeMaxWeight);
				
				if(maxWeight>city->maxWeight)
				city->maxWeight=maxWeight;
			}
			
			if(!city->isVisit&&(nextCity==NULL||city->maxWeight>nextCity->maxWeight))
			nextCity=city;
		}
		
		currentCity=nextCity;
		
	}while(currentCity!=NULL&&currentCity->maxWeight!=UNKNOWN_MAX_WEIGHT);
	
	return roadMap[targetName].maxWeight;
	
}

int main()
{
	int n,r;
	
	int caseNumber=1;
	
	while(cin >> n >> r)
	{
		if(n==0&&r==0)
		break;
		
		map<string,City>roadMap;
		int i;
		
		for(i=0;i<r;i++)
		{
			string sourceCityName,targetCityName;
			int maxWeight;
			
			cin >> sourceCityName >>targetCityName>>maxWeight;
			
			if(roadMap.find(sourceCityName)==roadMap.end())
			{
				roadMap[sourceCityName]=(City)
				{
					sourceCityName,map<string,int>(),UNKNOWN_MAX_WEIGHT
				};
			}
			
			if(roadMap.find(targetCityName)==roadMap.end())
			{
				roadMap[targetCityName]=(City)
				{
					targetCityName,map<string,int>(),UNKNOWN_MAX_WEIGHT
				};
			}
			
			int*sourceToTargetMaxWeightPrt=&roadMap[sourceCityName].edges[targetCityName];
			int*targetToSourceMaxWeightPrt=&roadMap[targetCityName].edges[sourceCityName];
			*sourceToTargetMaxWeightPrt=max(*sourceToTargetMaxWeightPrt,maxWeight);
			*targetToSourceMaxWeightPrt=max(*targetToSourceMaxWeightPrt,maxWeight);
			
		}
		
		string sourceCityName,targetCityName;
		
		cin >>sourceCityName>>targetCityName;
		
		cout <<"Scenario #"<<caseNumber<<endl;
		cout <<findMaxWeight(roadMap, sourceCityName, targetCityName)<<" tons"<<endl;
		
		cout << endl;
		
		caseNumber++;
	}
	
	return 0;
}
