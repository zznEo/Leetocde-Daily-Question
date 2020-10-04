#include <bits/stdc++.h>
using namespace std;
const int HASH_SIZE = 13;//hash表长度

struct Node{
	int data;
	struct Node *next;
};
static Node* HashTable[HASH_SIZE];//定义一个hash数组，该数组的每个元素是一个hash结点指针,并且由于是全局静态变量,默认初始化为NULL

unsigned int Hash_key(int key){
	return key % HASH_SIZE;	//哈希函数
}

Node* LookUp(int key){
	unsigned int HashValue = Hash_key(key);
	Node* np = HashTable[HashValue];
	//这里是链地址法解决的冲突,返回的是第一个链表结点
	while(np){
		//当两个数字相等时才能返回
		if(np->data = key)
			return np;
		np = np->next;
	}
	return nullptr;
}

int Search(int key){
	Node* np = LookUp(key);
	if(np == nullptr)
		return -1;
	else 
		return np->data;
}

Node *malloc_Node(int key){
	//在堆上为结点分配内存，并填充结点
	Node *np = new Node;
	if(np == nullptr)
		return nullptr;
	
	np->data = key;
	np->next = nullptr;
	return np;
}

int Insert(int key){
	unsigned int HashValue;
	HashValue = Hash_key(key);

	Node* np = malloc_Node(key);
	if(np == nullptr)
		return 0;
	//头插法，不管该hash位置有没有其他结点，直接插入结点
	np->next = HashTable[HashValue];
	HashTable[HashValue] = np;
	return 1;
}

//显示hash表元素（不包括空）
void DisplayHashTable(){
	Node* head = nullptr;
	unsigned int HashValue;
	for(int i = 0;i < HASH_SIZE;i++){
		if(HashTable[i] != nullptr){
			head = HashTable[i];
			cout << "i = " << i << ":" << endl;
			while(head){
				cout << head->data << " ";
				head = head->next;
			}
			cout << endl;
		}
	}
}

//清空hash表
void CleanHashTable(){
	Node *head = nullptr, *pre = nullptr;
	for(int i = 0;i < HASH_SIZE;i++){
		if(HashTable[i] == nullptr)
			continue;
		head = HashTable[i];
		while(head){
			pre = head->next;
			delete head;
			head = pre;
		}
	}
}

int main(){
	int a[] = {26, 36, 41, 38, 44, 15, 68, 12, 6, 51, 25};

	for(int i=0; i < 11; ++i)
        Insert(a[i]);

	printf("we should see %d\n",Search(26));
	Insert(41);//这里计算的hash是冲突的，为了测试冲突情况下的插入
    DisplayHashTable();
    CleanHashTable();

	system("pause");
}

#if 0
int Hash[10];
int mod = 8;
int a[10];

inline void init(){
    memset(Hash, -1, sizeof(Hash));
}

inline int Hash_key(int key){
    return key % mod;
}

void Insert(int key){
    int addr = Hash_key(key);
    while(Hash[addr] != -1){
        addr = Hash_key(addr + 1);
    }
    Hash[addr] = key;
}

int Search(int key){
    int addr = Hash_key(key);
	int pre = addr;
	while (Hash[addr] != key) {
		addr = Hash_key(addr + 1);
		if (Hash[addr] == -1 || Hash[addr] == pre) return -1;  // 返回了原点代表饶了一圈，此位置都为空了，说明值不存在，不然怎么也会放到这里
	}
	return addr;
}

int main(){
    init();
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		Insert(a[i]);
	}
	int x;
	while (cin >> x) {
		if (x == 0) break;
		int pos = Search(x);
		if (Hash[pos] == x)
			cout << pos << "   " << Hash[pos] << endl;
		else
			cout << "no have" << endl;
	}
    system("pause");
    return 0;
}
/*
5
9 10 11 19 27
*/
#endif