#include "Poset.h"
using namespace std;

void Poset::get_number(){
putin:
	cout<<"Please input a positive integer:";
	cin>>integer;
	if (integer<=0){
		cout<<"It isn\'t a positive integer!"<<endl;
		goto putin;
	}
}

void Poset::get_factor(){
	for (int i=1;i<=(int)integer/2;++i){
		if (integer%i==0){
			factor.push_back(i);
		}
	}
	factor.push_back(integer);
}

void Poset::get_cover(){
	vector<int> trans_dom;	//我是索引
	vector<int> trans_ran;
	relation.resize(factor.size());
	for (int i=0;i<factor.size();++i){	//填充关系阵
		relation[i].resize(factor.size());
		for (int j=i+1;j<factor.size();++j){
			if (factor[j]%factor[i]==0){
				relation[i][j]=1;
				trans_dom.push_back(factor[i]);
				trans_ran.push_back(factor[j]);
			}else relation[i][j]=0;
		}
	}
	for (int i=0;i<trans_dom.size();++i){
		for (int j=i+1;j<trans_dom.size();++j){
			if ((trans_ran[i]==trans_dom[j])&&(trans_ran[j]%trans_dom[i]==0)){
//				cout<<"<"<<trans_dom[i]<<","<<trans_ran[i]<<">,<"<<trans_dom[j]<<","<<trans_ran[j]<<">"<<endl;
//				cout<<"<"<<trans_dom[i]<<","<<trans_ran[j]<<">"<<endl;
//				cout<<find(factor.begin(),factor.end(),trans_dom[i])-factor.begin()<<"--->"<<find(factor.begin(),factor.end(),trans_ran[j])-factor.begin()<<endl;
				relation[find(factor.begin(),factor.end(),trans_dom[i])-factor.begin()][find(factor.begin(),factor.end(),trans_ran[j])-factor.begin()]=0;
			}
		}
	}
}

void Poset::print_factor(){
	cout<<"factors:";
	for (int i=0;i<factor.size()-1;++i) cout<<factor[i]<<',';
	cout<<factor[factor.size()-1]<<endl;
}

void Poset::print_cover(){
	cout<<"poset:{";
	for (int i=0;i<relation.size();++i){
		for (int j=i;j<relation[i].size();++j){
			if(relation[i][j]) cout<<'<'<<factor[i]<<','<<factor[j]<<'>'<<',';
		}
	}
	cout<<"\b}"<<endl;
}

int Poset::euclid(int a,int b){ //辗转相除法
	int gcd=a%b;
	if (gcd) b=euclid(b,gcd);
	return b;
}

int Poset::get_lcm(int a,int b){	//两数之积除以最大公约数即是最小公倍数
	int gcd;
	if(a<b){
		gcd=a;
		a=b;
		b=gcd;
	}
	gcd=euclid(a,b);
	return a*b/gcd;
}

void Poset::get_complement(){
	bool complement=false;
	for(int i=1;i<factor.size()-1;++i){
		complement=false;
		for (int j=1;j<factor.size()-1;++j){
			if (get_lcm(factor[i], factor[j])==integer) complement=true;
		}
		if (!complement) break;
	}
	if (complement) cout<<"It\'s a complemented lattice!"<<endl;
	else cout<<"It\'s not a complemented lattice!"<<endl;
}