
// ecs36b first program

#include <iostream>
#include "ecs36b_Exception.h"
#include <fstream>

// JSON RPC part
#include "hw6client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

int
main()
{
  // distributed wordle demo for 11/23/2022
   //HttpClient httpclient("http://127.0.0.1:8384");
  HttpClient httpclient("https://2ada-73-66-168-157.ngrok.io");
  hw6Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value jv_list;
  
  jv_list[0] = "918534383";
  jv_list[1] = "919373284";
  jv_list[2] = "919638424";
  jv_list[3] = "919589230";
  
 
/*

  try {
    myv = myClient.set_name("set_name", jv_list, "akame");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;





  try {
    // worry
    myv = myClient.guess("guess", "Wordle", "19056_2022-11-24T20:26:16+0000",
			 "worry");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;






  try {
    // worry
    myv = myClient.submit("submit", "19056_2022-11-24T20:26:16+0000", "foo");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;



*/




  // obtain and new
  //
  //
  
int o;

for(o=0;o<30;o++){
  try {
    myv = myClient.obtain("obtain", "Wordle", "00000000");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  std::string gid = myv["game_id"].asString();

  std::cout << gid << std::endl;


  

  try {
    // worry
    myv = myClient.guess("guess", "Wordle", gid,
			 "brick");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  
    try {
    // worry
    myv = myClient.guess("guess", "Wordle", gid,
			 "glent");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  
    try {
    // worry
    myv = myClient.guess("guess", "Wordle", gid,
			 "waqfs");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  
    try {
    // worry
    myv = myClient.guess("guess", "Wordle", gid,
			 "jumpy");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  
    try {
    // worry
    myv = myClient.guess("guess", "Wordle", gid,
			 "vozhd");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  

  
    std::string brick = myv["guesses"]["data"][0]["result"].asString();
    std::string glent = myv["guesses"]["data"][1]["result"].asString();
    std::string waqfs = myv["guesses"]["data"][2]["result"].asString();
    std::string jumpy = myv["guesses"]["data"][3]["result"].asString();
    std::string vozhd = myv["guesses"]["data"][4]["result"].asString();

    std::string w1="brick" ;
    std::string w2="glent" ;
    std::string w3="waqfs" ;
    std::string w4="jumpy" ;
    std::string w5="vozhd" ;

    std::string wlist="";

    int i=0;

     if(brick[i]=='#'){
      std::cout<<"1";
     }

    

    for(i=0;i<5;i++){
      if(brick[i]=='#'){
          wlist+=w1[i];
      }
      if(brick[i]=='o'){
          wlist+=w1[i];
      }
    }
    for(i=0;i<5;i++){
      if(glent[i]=='#'){
          wlist+=w2[i];
      }
      if(glent[i]=='o'){
          wlist+=w2[i];
      }
    }
    for(i=0;i<5;i++){
      if(waqfs[i]=='#'){
          wlist+=w3[i];
      }
      if(waqfs[i]=='o'){
          wlist+=w3[i];
      }
    }
    for(i=0;i<5;i++){
      if(jumpy[i]=='#'){
          wlist+=w4[i];
      }
      if(jumpy[i]=='o'){
          wlist+=w4[i];
      }
    }
    for(i=0;i<5;i++){
      if(vozhd[i]=='#'){
        wlist+=w5[i];
      }
      if(vozhd[i]=='o'){
        wlist+=w5[i];
      }
    }




  

  std::ifstream input("lists/SOLUTION.TXT");
	string s1;
	
	
	cout<< wlist<<endl<<"running"<<endl;


  int j,x;
	x=0;
	while(input>>s1){
			for(j=0;j<wlist.size();j++){
				if(s1.find(wlist[j]) != std::string::npos){
					x+=1;                

	
				}
				else{
					break;
				}
				
			}
			if(x==wlist.size()){
				cout<<s1;

												 try {
    // worry
    myv = myClient.guess("guess", "Wordle", gid,
			 s1);
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout<<myv;

    try {
    // worry
    myv = myClient.submit("submit",gid, "akame");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;
				
			}	
			x=0;	
	}

	input.close();




}





  return 0;
}
