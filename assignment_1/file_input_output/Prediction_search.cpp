/*time complexity
for insert operation- O(String_length)
for Search - O(N* keylength) where N is number of input strings (in worst case whole tree will be output)
Space Complexity- O(N* keylength)
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


// structure to represent the node of n-ary tree
struct node{ 

	node *children[256];    //array of pointers pointing to successors of a node. 26 possible characters are there.
	int isleaf;            //tells the number of occurances of string
};

//function to return a new node
node* getnode(){
	int i;
	node *temp=NULL;
	temp=(node*)malloc(sizeof (node));//memory allocation to new node created

	if(temp){//if free memory isn't available then NULL is returned
		temp->isleaf=0;
		for(i=0; i<256; i++){
			temp->children[i]=NULL;
		}
	}
	return temp;
}

// insert a new string into the tree
void insert(node *root, string s){
	int l=s.length(), i;
	node *temp=root;
	for(i=0; i<l; i++){
		if(!temp->children[s[i]]){
			//temp does not have required child so, create one
			temp->children[s[i]]=getnode();
		}
		temp=temp->children[s[i]];
	}
	temp->isleaf++;//now temp is a leaf and points to the end of inserted string
	
}

// returns address of the node where search key ends in the tree
node* searchprefix(node * root, string s){
	int l=s.length(), i;
	node *temp=root;
	if(!temp)return NULL;
	for(i=0; i<l; i++){
		if(!temp->children[s[i]]){
			return NULL;
		}
		temp=temp->children[s[i]];
	}
	return temp;
}

// traverse all the required strings in the subtree corresponding to given prefix
void depth_first_search(node* temp, string s){
	int count=temp->isleaf;
	while(count--){
		cout<<s<<endl;
	}
	for(int i=0; i<256; i++){
		if(temp->children[i]){
			char c=(char)(i);
			string t=s+c;
			depth_first_search(temp->children[i], t);
		}
	}
}
//main
int main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	string s;
	int i;
	int number_of_inputs, test_cases;

	node *root= getnode();

	cin>>number_of_inputs;
	while(number_of_inputs--){
		cin>>s;				// input string 
		insert(root, s);	// function to insert string in tree
	}

	cin>>test_cases;
	while(test_cases--){
		cin>>s;				//prefix string to be searched

		node* prenode=searchprefix(root, s);  
		// prenode is the address of node where search key ends in the tree
		if(prenode==NULL)cout<<"Key not present\n";
		else{
			//dfs is depth first search to traverse the n-ary tree to get required output
			depth_first_search(prenode, s);
		}
	}
	return 0;
}//109581
