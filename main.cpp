#include <string>
#include <iostream>
#include <vector>
using namespace std;

class big_num
{
public:
  vector <int>u_int = { 0 };

   vector <int>setstr (string str)
  {
    if (str.at (0) != '-'){
    u_int =  {};
     for (int i = 0; i < str.length (); i++){
      u_int.push_back (str.at (i) -= 48);
       }
     }

    else if (str.at(0) == '-'){

     u_int = {};
     u_int.push_back (-1);
     for (int i = 1; i < str.length(); i++){
      u_int.push_back (str.at (i) -= 48);
      }
   }
  return u_int;
 }

 void outstr (){

    if (u_int.at(0) != -1){
     for (int i = 0; i<u_int.size(); i++){
         cout << u_int.at(i);

     }
      }
      else {
          cout << "-";
         for (int i = 1; i<u_int.size(); i++){
          cout << u_int.at(i);
         }

      }

 }

  int at(int pos){

     if (pos < 0 || pos > u_int.size()){
         return -1;
     }

     else{
        return u_int.at(pos);
        }
     }


    int relativeat(int pos){

     if (pos < 0 || pos > u_int.size()){
         return -1;
     }

     else{

      if (u_int.at(0) != -1){
        return u_int.at(pos);
      }

      else {
        return u_int.at(pos+1);
      }

    }

}


  vector<int> change(int pos, int num){
     if(pos > 0 || pos < u_int.size()){
      u_int.at(pos)+=num;
      return u_int;

    }

 }

 int compare(big_num num1, big_num num2){
    for (int i = 0; i<num1.size(); i++){
      if (num1.relativeat(i)>num2.relativeat(i)){
        return 1;
        // if num1 is larger
     }
     else {
        return -1;
     }
    }

    return 0;
  }



 int size(){

     if (u_int.at(0)!=-1){
     return u_int.size();
     }
     else{
         return u_int.size()-1;
     }
 }

void insert(int pos, signed int num){

     if (num < 10 && num >= 0){
     u_int.insert(u_int.begin()+pos, num);
     }


 }





 vector<int> add (big_num num1, big_num num2){
    u_int = {0};

    // addition for both integers when they are both positive
    if (num1.at(0)!=-1 && num2.at(0)!=-1){

      if (num1.size()>num2.size()){
       while(num1.size()>num2.size()){
           num2.insert(0,0);
       }
      }


    if (num1.size()<num2.size()){
       while(num1.size()<num2.size()){
           num1.insert(0,0);
       }
      }


     for (int i = 0; i<num1.size();i++){
         u_int.push_back(num1.at(i)+num2.at(i));

     }

     for (int i = u_int.size()-1; i>0; i--){
         if (u_int.at(i)>=10){
             u_int.at(i)-=10;
             u_int.at(i-1)++;

         }


     }

     if (u_int.at(0) == 0){
        u_int.erase(u_int.begin() + 0);
     }
    }



    // addition when a number is negative
   else if (num1.at(0)!=-1 && num2.at(0)==-1 || num1.at(0)==-1 && num2.at(0)!=-1 ){


   // aligning process
    if(num1.size()<num2.size()){
     if (num1.at(0) == -1){
      while(num1.size()<num2.size()){
        num1.insert(1,0);
      }
     }
    else if (num1.at(0) != -1){
      while(num1.size()<num2.size()){
        num1.insert(1,0);
      }
     }
    }

    if(num2.size()<num1.size()){
     if (num2.at(0) == -1){
      while(num2.size()<num1.size()){
        num2.insert(1,0);
      }
     }
    else if (num2.at(0) != -1){
      while(num2.size()<num1.size()){
        num2.insert(1,0);
      }
     }
    }

    for (int i = 1; i<num1.size(); i++){
        u_int.push_back(0);
    }

    // end of aligning process

    // addition process

    // code for if num1 is negative (incomplete)
    if (num1.at(0) == -1){



    }



         // code for if num2 is negative (incomplete)
        else if (num2.at(0) == -1){
            
            // code if abs(num2) is less than num1 (complete)
          if (compare(num1,num2) == 1){
              for (int i = num1.size()-1; i>=0; i--){
                  u_int.at(i) = num1.at(i)-num2.at(i+1);
                  
                }
                 for (int i = num1.size()-1; i>=0; i--){
                  if (u_int.at(i) < 0){
                    
                     u_int.at(i)=10+u_int.at(i);
                     u_int.at(i-1)-=1; 
                  }
              }
          }
          // code for if abs(num2) is more than num1 (incomplete)
          if (compare(num1,num2) == -1){
              
            for (int i = num2.size()-1; i>=0; i--){
              u_int.at(i) = num2.at(i+1)-num1.at(i);
            }
               
             for (int i = num1.size()-1; i>=0; i--){
                 if (u_int.at(i) < 0){
                
                     u_int.at(i)=10+u_int.at(i);
                     u_int.at(i-1)-=1; 
                  }
                  
              }


          }
          
         
         
         
        }
   }
   return u_int; 
  }
   
};

int main ()
{

  big_num test;
  big_num num1;
  big_num num2;

  num1.setstr("1");
  num2.setstr("-2");
  test.add(num1, num2);

  test.outstr();



  return 0;
}
