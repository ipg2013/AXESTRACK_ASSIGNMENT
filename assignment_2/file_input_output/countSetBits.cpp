/*
Time Complexity O(log base 2 of number)
Space complexity O(1)
*/
#include<bits/stdc++.h>
using namespace std;
#define fr(i, a, b) for(i=a; i<b; i++)
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define ll long long
const ll inf= 9999999999LL;
const ll mo=1000000007LL;

//returns the address of first element of array containing position of set bits in the number
int *getSetBits(ll number){
	static int array[40]={}, i=0;// array initialised to 0
	//array needs to be static because returning address of a local variable will give garbage values.
	for(i=0; i<40; i++)array[i]=0;
	i=0;
	while(number){
		if(number%2){
			array[i]=1;//if number is odd, set the bit
		}
		i++;
		number/=2;
	}
	return array;
}

//main
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		ll number;
		int *array_for_set_bits, i;//declare a pointer to hold the value of returned address of array
		cin>>number;
		array_for_set_bits=getSetBits(number);
		cout<<"{";
		for(i=0; i<40; i++){
			if(array_for_set_bits[i])cout<<i<<" ";
		}
		cout<<"}\n";
	}
	
}