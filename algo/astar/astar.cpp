#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{
	int x;
	int y;
	int val;
	int num;
	struct Node * from;
	Node(Node * a, int xval, int yval, int valval){
		x = xval;
		y = yval;
		val = valval;
		from = a;
		num = (a->num)+1;
	}
	Node(int xval, int yval, int valval){
		x = xval;
		y = yval;
		val = valval;
	}
	void printNode(){
		printf("(%d,%d), value=%d, from (%d, %d), num=%d\n", this->x, this->y, this->val, this->from->x, this->from->y, this->num);	
	}
	void printx(){
		printf("%d", this->x);
	}
	void copy(Node * a){
		this->x = a->x;
		this->y = a->y;
		this->val = a->val;
		this->from = a->from;
	}
};


bool sameCoor(Node * a, Node * b){
	return 1 ? (a->x==b->x)&&(a->y==b->y) : 0;
}

void pushpq(vector<Node>& pq,Node * node){
	if(pq.size()==0){	
		pq.push_back(*node); return;
	}
	auto iter = pq.begin();
	for (int i=0; i<pq.size(); i++){
		if (node->val>pq[i].val){
			iter++;
		}
	}	
	iter = pq.insert(iter, *node);
	return;
}

int main(){
	int matrix [7][6] {0};
	for (int i=0; i<7; ++i){
		for (int j=0; j<6; ++j) matrix[i][j]=1;
	}
	Node null(-1,-1,-1);
	Node start(&null, 0,0,0);
	Node end(&null, 6,5,0);
	Node cur(&null, 0,0,0);
	cur.num=1;
	vector<Node> pq;
	vector<Node> buffer;
	int counter = 0;
	while(!sameCoor(&cur, &end)){
		cout<<"cur: ";
		cur.printNode();
		buffer.push_back(Node(&cur, cur.x-1, cur.y,(6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+ cur.val+matrix[cur.x][cur.y]));
		buffer.push_back(Node(&cur, cur.x+1, cur.y, (6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+cur.val+matrix[cur.x][cur.y]));
		buffer.push_back(Node(&cur, cur.x, cur.y+1, (6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+cur.val+matrix[cur.x][cur.y]));
		buffer.push_back(Node(&cur, cur.x, cur.y-1, (6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+cur.val+matrix[cur.x][cur.y]));
		for(Node &i: buffer){
			if (sameCoor(cur.from, &i)){
				continue;
			}
			if(((i.x>=0)&&(i.y>=0)&&(i.x<=6)&&(i.y<=5))&&(!sameCoor(cur.from, &i)))
				pushpq(pq, &i);
		}
		cur.copy(&pq[0]);
		pq.erase(pq.begin());
		// if ((cur.x+cur.y)>=11) break;
		// if (counter>8) break;
		// for (Node &i:pq) i.printNode();
		// cout<<endl;
		counter++;
		buffer.clear();
	}
	// for (Node &i:pq) i.printNode();
	Node try1(&null, 1,2,3);
	Node try2(&null, 1,2,3);
	pushpq(pq, &start);	
	pushpq(pq, &end);	
	pushpq(pq, &try1);	
	pushpq(pq, &try2);	
	Node a(&cur, cur.x-1, cur.y,(6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+ cur.val+matrix[cur.x][cur.y]);
	// pq.push_back(Node(&cur, cur.x-1, cur.y,(6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+ cur.val+matrix[cur.x][cur.y]));
	pq.push_back(a);
	// cur.copy(&pq[0]);
	pq.push_back(Node(&cur, cur.x-1, cur.y,(6-cur.x)*(6-cur.x)+(5-cur.y)+(5-cur.y)+ cur.val+matrix[cur.x][cur.y]));

	for (Node &i:pq) i.printNode();

	vector<int> vecint(2,3); 
	// auto iter = vecint.begin()+1;
	// iter = vecint.insert(iter, 20);
	// // vecint.insert(iter, 30);
	// for (int i: vecint) cout<<i<<" "<<endl;
	return 0;
}
