#include <iostream>
#include <cmath>
#include <map>
#include <vector>

#define WDT 70
#define HET 600

using namespace std;

struct Node{
	int x;
	int y;
	int val;
	int num;
	struct Node * from;
	int fromx, fromy;
	float heuristic;
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
};

bool sameCoor(Node * a, Node * b){
	return 1 ? (a->x==b->x)&&(a->y==b->y) : 0;
}

void pushpq(vector<Node>& pq,Node * node){
	if(pq.size()==0){	
		pq.push_back(*node); return;
	}
	auto iter = pq.begin();
	for (int i=0; i<pq.size(); i++){ // With heuristic
		if (node->val+node->heuristic<=pq[i].val+pq[i].heuristic) break;
		iter++;
	}	
	
	// for (int i=0; i<pq.size(); i++){ // No heuristic
	// 	if (node->val<=pq[i].val) break;
	// 	iter++;
	// }	
	iter = pq.insert(iter, *node);
	return;
}

void astar(Node * start, Node * end){
	int matrix [WDT][HET] {0};
	for (int i=0; i<WDT; ++i){
		for (int j=0; j<HET; ++j) matrix[i][j]=1;
	}

	// matrix[5][1] = 10000;
	// matrix[1][1] = 10000;
	// matrix[4][2] = 10000;
	// matrix[6][2] = 10000;
	// matrix[0][3] = 10000;
	// matrix[4][3] = 10000;
	// matrix[1][4] = 10000;
	// matrix[4][5] = 10000;

	Node null(-1,-1,-1);
	Node *nodeMatrix[WDT][HET];
	
	for(int i=0; i<WDT; i++){
		for(int j=0; j<HET; j++){
			nodeMatrix[i][j]=new Node(&null);
			nodeMatrix[i][j]->x=i;
			nodeMatrix[i][j]->y=j;
			// Edit Heuristic function here
			nodeMatrix[i][j]->heuristic= (float)sqrt((end->x-i)*(end->x-i)+(end->y-j)*(end->y-j));
			// nodeMatrix[i][j]->heuristic=1;
		}
	}
	int curCo [2] = {start->x, start->y};
	nodeMatrix[start->x][start->y]->val=0;
	nodeMatrix[start->x][start->y]->num=0;
	vector<Node> pq;
	vector<int*> buffer;
	int counter{0};
	
	while((curCo[0]!=end->x)||(curCo[1]!=end->y)){
		counter++;
		buffer.push_back(new int[2]{curCo[0]+1,curCo[1]});
		buffer.push_back(new int[2]{curCo[0]-1,curCo[1]});
		buffer.push_back(new int[2]{curCo[0],curCo[1]+1});
		buffer.push_back(new int[2]{curCo[0],curCo[1]-1});
		for (auto i:buffer){
			if((i[0]>=0)&&(i[1]>=0)&&i[0]<WDT&&i[1]<HET
				 &&((i[0]!=nodeMatrix[curCo[0]][curCo[1]]->fromx)
				 ||(i[1]!=nodeMatrix[curCo[0]][curCo[1]]->fromy))
				&&(nodeMatrix[curCo[0]][curCo[1]]->val+1<nodeMatrix[i[0]][i[1]]->val)
			){  
				// nodeMatrix[i[0]][i[1]]->val = matrix[i[0]][i[1]]+nodeMatrix[curCo[0]][curCo[1]]->val+nodeMatrix[i[0]][i[1]]->heuristic;
				nodeMatrix[i[0]][i[1]]->val = matrix[i[0]][i[1]]+nodeMatrix[curCo[0]][curCo[1]]->val;
				nodeMatrix[i[0]][i[1]]->num = nodeMatrix[curCo[0]][curCo[1]]->num+1;
				nodeMatrix[i[0]][i[1]]->fromx = curCo[0];
				nodeMatrix[i[0]][i[1]]->fromy = curCo[1];
				pushpq(pq, nodeMatrix[i[0]][i[1]]);
			}
		}
		// Clear buffer
		for (auto i:buffer){
			delete[] i;
		}
		buffer.clear();

		curCo[0] = pq[0].x;
		curCo[1] = pq[0].y;
		pq.erase(pq.begin());
	}
	// for (int i=0; i<HET; i++){
	// 	for(int j=0; j<WDT; j++){
	// 		cout<<" "<<nodeMatrix[j][i]->fromx<<","<<nodeMatrix[j][i]->fromy<<" ";
	// 	}
	// 	cout<<endl;
	// }
	

	cout<<"Number of steps: "<<nodeMatrix[curCo[0]][curCo[1]]->num<<endl;
	int a = curCo[0];int b=curCo[1];
	int retraceCounter = 0;
	while(a!=start->x||b!=start->y){
		cout<<retraceCounter++<<": "<<a<<", "<<b<<endl;
		int ta = a;
		int tb = b;
		a = nodeMatrix[ta][tb]->fromx; b=nodeMatrix[ta][tb]->fromy;
	}
	cout<<start->x<<", "<<start->y<<endl;
	printf("Number of Iterations: %d\n", counter);
	return;
}

int main(){
	// Edit start and end here:
	Node start(WDT/10,HET/20,0);
	Node end(WDT/2, HET/4, 0);
	astar(&start, &end);
	
	return 0;
}
