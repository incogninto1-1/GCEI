#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int pak, rev, pnt, com;
	ifstream rep;
	rev=0;
	pnt=1;
	cout<<"GCEI (Grab it, Check it, Extract it, Install it) Version "<<rev<<"."<<pnt<<endl<<"Copyleft 2022 8X Computing Squad"<<endl<<"No Rights Reserved"<<endl;
	cout<<"Warning: This product is FREE DAMN SOFTWARE under GNU GPL 3.0."<<endl<<"Any redistributions of this product will be ignored "<<endl<<"For more info go to www.gnu.org/philosophy/free-sw.en.html"<<endl<<"1 for manual"<<endl;
	rep.open("/etc/gcei/repo.conf");
	if (!rep){
		cerr << "Cannot read /etc/gcei/repo.conf"<<endl<< "Troubleshoot: Are you running GCEI as a superuser?"<<endl<<"If yes have you ran gcei-conf?"<<endl;
		return 1;
	}
	while(true){
		cout<<"GCEI>";
		cin>>com;
		if(com==1){
			cout<<"GCEI (Grab it, Check it, Extract it, Install it) user manual"<<endl<<"1=manual"<<endl<<"2=install package"<<endl<<"3=remove package"<<endl<<"4=refresh"<<endl<<"5=list package adresses"<<endl<<"6=quit"<<endl;
		}
		if(com==2){
			cout<<"Now enter the package address"<<endl;
			cin>>pak;
			if(pak<=255){
				cout<<"Grab it"<<endl;
				cout<<"Not available yet but it is gonna use wget"<<endl;
				cout<<"Check it"<<endl;
				cout<<"insert MD5 checker here"<<endl;
				cout<<"Extract it"<<endl;
				cout<<"I can use tar"<<endl;
				cout<<"Install it"<<endl;
				cout<<"gonna use mv /tmp/packagename /usr/bin/packagename"<<endl;
				cout<<"Done!"<<endl;
			}
			else
				cout<<"Package not available!"<<endl;
		}
		if(com==6){
			cout<<"Goodbye!"<<endl;
			return 0;
		}
		else{
			cout<<"Wut?"<<endl;
		}
	}
	return 0;
}
