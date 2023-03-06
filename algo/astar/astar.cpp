#include <iostream>
#include <map>
#include <vector>

#define WDT 7
#define HET 6

using namespace std;

struct Node{
	int x;
	int y;
	int val;
	int num;
	struct Node * from;
	int fromx, fromy;
	Node(){
	}
	Node(Node * a){
		from = a;
		val = 100000;
	}
	Node(Node * a, int xval, int yval, int valval){
		x = xval;
		y = yval;
		val = valval;
		fromx = a->x;
		fromy = a->y;
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
		this->num = a->num;
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

void astar(Node * start, Node * end){
	int matrix [WDT][HET] {0};
	for (int i=0; i<7; ++i){
		for (int j=0; j<6; ++j) matrix[i][j]=1;
	}
	matrix[5][1] = 10000;
	matrix[1][1] = 10000;
	matrix[4][2] = 10000;
	matrix[6][2] = 10000;
	matrix[0][3] = 10000;
	matrix[4][3] = 10000;
	matrix[1][4] = 10000;
	matrix[4][5] = 10000;

	Node null(-1,-1,-1);
	Node *nodeMatrix[WDT][HET];
	
	for(int i=0; i<WDT; i++){
		for(int j=0; j<HET; j++){
			nodeMatrix[i][j]=new Node(&null);
			nodeMatrix[i][j]->x=i;
			nodeMatrix[i][j]->y=j;
		}
	}
	// for(int i=0; i<WDT; i++){
	// 	for(int j=0; j<HET; j++){
	// 		cout<<i*HET+j<<": "; nodeMatrix[i][j]->printNode();
	// 	}
	// }
	int curCo [2] = {start->x, start->y};
	nodeMatrix[start->x][start->y]->val=0;
	nodeMatrix[start->x][start->y]->num=0;
	vector<Node> pq;
	vector<int*> buffer;
	int counter = 0;
	
	while((curCo[0]!=end->x)||(curCo[1]!=end->y)){
		buffer.push_back(new int[2]{curCo[0]+1,curCo[1]});
		buffer.push_back(new int[2]{curCo[0]-1,curCo[1]});
		buffer.push_back(new int[2]{curCo[0],curCo[1]+1});
		buffer.push_back(new int[2]{curCo[0],curCo[1]-1});
		for (auto i:buffer){
			cout<<"Current buffer: "<<"x: "<<*i<<"; y: "<<*(i+1)<<endl;
		}
		for (auto i:buffer){
			if((i[0]>=0)&&(i[1]>=0)&&i[0]<WDT&&i[1]<HET
				 &&((i[0]!=nodeMatrix[curCo[0]][curCo[1]]->fromx)
				 ||(i[1]!=nodeMatrix[curCo[0]][curCo[1]]->fromy))
				&&(nodeMatrix[curCo[0]][curCo[1]]->val+1<nodeMatrix[i[0]][i[1]]->val)
			){
				nodeMatrix[i[0]][i[1]]->val = matrix[i[0]][i[1]]+nodeMatrix[curCo[0]][curCo[1]]->val; //Insert heuristic here
				nodeMatrix[i[0]][i[1]]->num = nodeMatrix[curCo[0]][curCo[1]]->num+1;
				nodeMatrix[i[0]][i[1]]->fromx = curCo[0];
				nodeMatrix[i[0]][i[1]]->fromy = curCo[1];
				pushpq(pq, nodeMatrix[i[0]][i[1]]);
				// pq.push_back(*nodeMatrix[i[0]][i[1]]);
			}
		}
		for (auto i:buffer){
			delete[] i;
		}
		buffer.clear();
		for (auto i:pq){
			i.printNode();
		}
		cout<<endl;
		curCo[0] = pq[0].x;
		curCo[1] = pq[0].y;
		pq.erase(pq.begin());
		cout<<"curCo: "<<curCo[0]<<", "<<curCo[1]<<endl;
		cout<<"num: "<<nodeMatrix[curCo[0]][curCo[1]]->num<<endl;
		// if(counter++>10) break;
	}
	for (int i=0; i<HET; i++){
		for(int j=0; j<WDT; j++){
			cout<<" "<<nodeMatrix[j][i]->fromx<<","<<nodeMatrix[j][i]->fromy<<" ";
		}
		cout<<endl;
	}
	

	int a = curCo[0];int b=curCo[1];

	while(a!=start->x||b!=start->y){
		cout<<a<<", "<<b<<endl;
		int ta = a;
		int tb = b;
		a = nodeMatrix[ta][tb]->fromx; b=nodeMatrix[ta][tb]->fromy;
	}
	cout<<start->x<<", "<<start->y<<endl;
	return;
}

int main(){
	Node start(6,1,0);
	Node end(WDT-1, HET-1, 0);
	astar(&start, &end);
	
	return 0;
}
