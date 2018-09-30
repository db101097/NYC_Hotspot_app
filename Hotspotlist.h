#ifndef __HOTSPOTLIST_H__
#define __HOTSPOTLIST_H__
#include<fstream>
#include"Hotspot.h"
#include "sortedlinklist.h"
using namespace std;

class Hotspotlist
{

	public:
	Hotspotlist(){};
	Hotspotlist(ifstream & input)
	{
		string line;
		while(!input.eof())
		{
			getline(input,line);
		
			if(line.length()==0)
			{
				continue;
			}

			else
			{
				Hotspot in(line);
				list.insert(in);
			}
		}
	};

	void insert(string input)
	{
			Hotspot x(input);
			list.insert(x);
	};

	void remove_by_id (int objid)
	{
			Hotspot x;
			x.set(objid,"","","","","",0,0,"");
			list.delete_node(x);
			
	};

	int size()
	{
		return list.length();
	};

	void retrieve( int objid )
	{
			Hotspot x;
			x.set(objid,"","","","","",0,0,"");
			list.find(x);
	};
	
	void find_boro(string boro , string tofile="boro_results")
	{
			
			ofstream o;
			o.open(tofile.c_str(),ofstream::app);
			bool success=false;
			o<<"These are all the hotspots found in "<<boro<<endl;
			for(Iterator<Hotspot> itr=list.begin(); itr!=list.end(); itr++)
			{
					if(boro==(*itr).GetBorough())
					{
							success=true;
							(*itr).print(o);
					}
			}

			if(success!=true)
			{
					o<<"No hotspots were found in "<<boro<<endl;
			}
			o.close();
			
	};
	
	void find_byId(int objid ,string tofile="ID_results")
	{
			ofstream o;
			o.open(tofile.c_str(),ofstream::app);
			bool success=false;
			o<<"This is the hotspot found with id "<<objid<<endl;
			for(Iterator<Hotspot> itr=list.begin(); itr!=list.end(); itr++)
			{
					if(objid==(*itr).GetId())
					{
							success=true;
							(*itr).print(o);
					}
			}
			if(success!=true)
			{
					o<<"No hotspots were found with id "<<objid<<endl;
			}
			o.close();
	};
	
	void nearby(double lat, double lon , float dist , string tofile="nearby_results")
	{
			ofstream o;
			o.open(tofile.c_str(),ofstream::app);
			bool success=false;
			o<<"These are the hotspot found nearby"<<endl;
			for(Iterator<Hotspot> itr=list.begin(); itr!=list.end(); itr++)
			{
					if((*itr).GetDistance(lat,lon)<=dist)
					{
							success=true;
							(*itr).print(o);
							o<<"The above hotspot above is "<<(*itr).GetDistance(lat,lon)<<" miles away"<<endl;
					}
			}
			
			if(success!=true)
			{
				o<<"No hotspots found within "<<dist<<endl;
			}

				o.close();

	};

	private:
	sortedlinklist <Hotspot> list;
};

#endif
