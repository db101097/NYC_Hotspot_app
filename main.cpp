#include<fstream>
#include<vector>
#include"Hotspot.h"
#include"Hotspotlist.h"
#include "sortedlinklist.h"
#include<ostream>
#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<limits>
using namespace std;
/*
commands
nearby lat long distance writefile
findbyid id writefile
findbyboro boro writefile
*/


int main (int argc , char * argv [])
{
	if(argc!=2)
	{
		cout<<"Not enough arguments passed."<<endl;
	}

	ifstream in(argv[1]);
	if(in.fail()!=true)
	{
		Hotspotlist x (in);
		string input,boro;
		int id;
		float lat ,lon,dist;
		while(true)
		{
			cout<<"Enter n for nearby, fid for findbyid , fbb for find by borough or E for exit "<<endl;
			cin>>input;

			if(input=="n")
			{
				cout<<"Enter your latittude"<<endl;
				cin>>lat;
				while(cin.fail())
				{
					  cin.clear();
				     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					 cout<<"Error , the value entered was invalid"<<endl;
					 cin>>lat;
				}
				cout<<"Enter your longitude"<<endl;
				cin>>lon;
				while(cin.fail())
				{
					cin.clear();
				     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					 cout<<"Error , the value entered was invalid"<<endl;
					 cin>>lat;
				}
				cout<<"Enter the acceptible distance (miles) from you"<<endl;
				cin>>dist;
				while(cin.fail())
				{
					 cin.clear();
				     cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					 cout<<"Error , the value entered was invalid"<<endl;
					 cin>>lat;
				}
				
				x.nearby(lat,lon,dist);
			}

			else if(input=="fid")
			{
					cout<<"Enter the id of the hotspot"<<endl;
					cin>>id;
					while(cin.fail())
					{
					 	cin.clear();
				     	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					 	cout<<"Error , the value entered was invalid"<<endl;
					 	cin>>id;
					}
					
					x.find_byId(id);
			}

			else if(input=="fbb")
			{
					cout<<"Enter the boro"<<endl;
					cin>>boro;
					while(boro!="QU" && boro!="MN" && boro!="BX" && boro!="SI" && boro!="BK")
					{
							cout<<"Error , the value entered was invalid"<<endl;
					 		cin>>boro;
					}
					
					x.find_boro(boro);
			}
		
			else if (input=="E")
			{
					exit(1);
			}

			else
			{
					cout<<"Unrecognized input "<<input<<" options are n , fid or fbb (case sensitive)."<<endl;
			}
		}
	}
	else
	{
			cout<<"The file "<<argv[1]<<" could not be opened"<<endl;
	}


}
