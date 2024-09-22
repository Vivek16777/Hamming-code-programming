//hamming code
#include <iostream>
#include <math.h>
using namespace std;
int total[10] ;
int calculateparity(int m){
    int r=0 ;
    while(pow(2,r) < m+r+1){
        r++ ;
    }
    return r ;  //calculting no. of parity bits
}
void encode(int m){
int data[m];
cout<<"enter the data you want to send (in bits) :";
for(int i=0 ; i<m ; i++){
    cin >> data[i];
} // taking inputs of data
int r = calculateparity(m) ;
int totalbits = m + r ;
int j=0;
for(int i=0 ;i < totalbits ; i++ ){
    total[i]=0;
}
for(int i = 1 ; i <= totalbits ; i++){
   if (i==pow(2,j)){
    j++;
   }
   else
    total[i-1] = data[i-j-1]; 
}    //inserting data bits
for(int i = 0 ; i < r ; i++){
    int paritypos = pow(2,i);
    int parityval = 0;
    for(int j = 1 ; j <= totalbits ; j++){
        if (j & paritypos){
        parityval ^= total[j-1]; //finding value of parity bit
        }
    }
    total[paritypos - 1] = parityval; //insert parity bit in array
}
cout << "encoded parity bits are : "<<endl;
for(int i = 0; i < totalbits ; i++){
    cout<<total[i]<<" ";
}
cout<<endl;
}
void decode(int m){
    int r = calculateparity(m) ;
    int totalbits = m + r ;
    int errorpos = 0;
   for(int i = 0 ; i < r ; i++){
    int paritypos = pow(2,i);
    int parityval = 0;
    for(int j = 1 ; j <= totalbits ; j++){
        if (j & paritypos){
        parityval ^= total[j-1]; //calculating parity bits
        }
    }
    if (parityval != 0){
        int errorpos = errorpos + parityval; //finding error position
    }
}
    if (errorpos != 0){
        cout<<"error detected at position : "<< errorpos ;
        total[errorpos - 1] ^= 1; // correcting error
      }
    else
       cout<<"no error"<<endl;
    
    cout<<"decoded data are : ";
    for(int i=1 ; i <= totalbits ; i++){
        if(pow(2,(int)log2(i))!=i){
            cout<<total[i-1]<<" ";
        }
    }
    
    }
int main(){
int m;
cout<<"enter the no. of bits you want to send : ";
cin>>m;
encode(m); // encoded data
decode(m); // decoded data if error then corrected it
return 0;
}