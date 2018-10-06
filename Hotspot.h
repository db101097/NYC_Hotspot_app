#ifndef __HOTSPOT_H__
#define __HOTSPOT_H__
#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<vector>
#include<cmath>
#include<math.h>
#include<fstream>
using namespace std;
class Hotspot
{

public:
// Default constructor ; fills fields with zeros or null strings
Hotspot (){};
		 
// Constructor that creates Hotspot object from a hotspot file text line
Hotspot(const string dataline)
{
			vector<string> info;
				istringstream s(dataline);
				string parsed,i;
				bool success=true;
				while (getline(s,parsed,','))
				{
					if(parsed.length()<1 || parsed[0]==' ' || parsed[parsed.length()-1]==' ' )
					{
							success=false;
					}

					else if(parsed[0]=='"')
					{

						i+=parsed+',';
						while(parsed[parsed.length()-1]!='"')
						{
								
								if(!getline(s,parsed,','))
								{
									success=false;
									break;
								}
								else if(parsed[parsed.length()-1]=='"')
								{
									i+=parsed;
								}
								else
								{
									i+=parsed+',';
								}
						}
						info.push_back(i);
						i="";
					}
				
					else
					{
						info.push_back(parsed);
					}		
				}

			if(info.size()==9 && success==true)
		{
			Objectid=atoi(info[0].c_str());
			Borough=info[1];
			Type=info[2];
			Provider=info[3];
			Name=info[4];
			Location=info[5];
			Latitude=atof(info[6].c_str());
			Longitude=atof(info[7].c_str());
			SSID=info[8];	
		}
							


};
		 
// Copy constructor
Hotspot ( const Hotspot &current)
{
		Objectid=current.Objectid;
		Borough=current.Borough;
		Type=current.Type;
		Provider=current.Provider;
		Name=current.Name;
		Location=current.Location;
		Latitude=current.Latitude;
		Longitude=current.Longitude;
		SSID=current.SSID;
};
		 
// Constructor to create a Hotspot object from nine separate data values 
Hotspot(int id,
	    string boro, 
	    string type, 
	    string prov,
	    string nameof,
	    string loc,
	    double lat,
	    double lon,
	    string wifiname)
{
		Objectid=id;
		Borough=boro;
		Type=type;
		Provider=prov;
		Name=wifiname;
		Location=loc;
		Latitude=lat;
		Longitude=lon;
		SSID=wifiname;
};

// Sets all nine data member
void set( const int id,
	    const string boro, 
	    const string type, 
	    const string prov,
	    const string nameof,
	    const string loc,
	    const double lat,
	    const double lon,
	    const string wifiname)
{
		Objectid=id;
		Borough=boro;
		Type=type;
		Provider=prov;
		Name=wifiname;
		Location=loc;
		Latitude=lat;
		Longitude=lon;
		SSID=wifiname;




};

//Gets all nine data members 
void get( int &id ,
	    string &boro , 
	    string &type ,
	    string &prov ,
	    string &nameof ,
	    string &loc ,
	    double &lat ,
	    double &lon,
	    string &wifiname)
{
		id=Objectid;
		boro=Borough;
		type=Type;
		prov=Provider;
		wifiname=Name;
		loc=Location;
		lat=Latitude;
		lon=Longitude;
		wifiname=SSID;
};
		  
double deg2rad(double deg) 
{
  return (deg * M_PI / 180);
}

double rad2deg(double rad) 
{
  return (rad * 180 / M_PI);
}
float GetDistance(float lat2 , float lon2)
{
  double lat1r, lon1r, lat2r, lon2r, u, v;
  double earthRadiusMi=3959;
  lat1r = deg2rad(Latitude);
  lon1r = deg2rad(Longitude);
  lat2r = deg2rad(lat2);
  lon2r = deg2rad(lon2);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusMi * asin(sqrt(u * u + cos(Latitude) * cos(lat2) * v * v));
};
  
  /** GetId() - returns the ObjectId of a given hotspot
    */
int GetId() const
{
	return Objectid;
};

void p()
{
	cout<<Objectid<<","<<Borough<<","<<Type<<","<<Provider<<","<<Name<<","<<Location<<","<<Latitude<<","<<Longitude<<","<<SSID<<endl;
};

void print(ofstream & o)
{
	o<<Objectid<<","<<Borough<<","<<Type<<","<<Provider<<","<<Name<<","<<Location<<","<<Latitude<<","<<Longitude<<","<<SSID<<endl;
};

string GetBorough()const
{
	return Borough;
};

/** Two friend comparison operators:
  * bool operator < (lt , rt) is true if and only if:
  *      lt.ObjectId < rt.ObjectId
  *bool operator == (lt , rt ) is true if and only if :
  *    lt.ObjectId == rt.ObjectId
  */
friend bool operator< (const Hotspot & lt , const Hotspot & rt )
{
		return lt.Objectid < rt.Objectid;
};
friend bool operator> (const Hotspot & lt , const Hotspot & rt )
{
		return lt.Objectid > rt.Objectid;
};
friend bool operator== (const Hotspot & lt , const Hotspot & rt )
{
			return lt.Objectid == rt.Objectid;
};


private :
int Objectid; 
string Borough;
string Type;
string Provider;
string Name;
string Location;
double Latitude;
double Longitude;
string SSID;
};
#endif		 
