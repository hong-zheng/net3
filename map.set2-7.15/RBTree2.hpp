//#include <time.h>
//#include <iostream>
//#include <utility>
//using namespace std;
//enum Color
//{
//	BLACK,
//	RED
//};
//
//template <class K, class V>
//struct RBNode
//{
//	pair<K, V> _value;
//	Color _color;
//	RBNode<K, V>* _parent;
//	RBNode<K, V>* _left;
//	RBNode<K, V>* _right;
//
//	RBNode(const pair<K, V>& value = pair<K, V>())
//		:_value(value)
//		, _color(RED)
//		, _parent(nullptr)
//		, _left(nullptr)
//		, _right(nullptr)
//	{}
//};
//
//template <class K, class V>
//class RBTree
//{
//public:
//	typedef RBNode<K, V> Node;
//
//	RBTree()
//		:_header(new Node)
//	{
//		_header->_left = _header->_right = _header;
//	}
//
//	bool insert(const pair<K, V>& val)
//	{
//		//����
//		if (_header->_parent == nullptr)
//		{
//			//������һ�����ڵ�
//			Node* root = new Node(val);
//			//���ڵ�Ϊ��ɫ
//			root->_color = BLACK;
//
//			_header->_parent = root;
//			root->_parent = _header;
//
//			_header->_left = root;
//			_header->_right = root;
//
//			return true;
//		}
//		//�ǿ���
//		Node* cur = _header->_parent;
//		Node* parent = nullptr;
//		while (cur)
//		{
//			parent = cur;
//			//����keyֵ���бȽϣ� pair.first
//			if (cur->_value.first == val.first)
//				return false;
//			if (cur->_value.first < val.first)
//				cur = cur->_right;
//			else
//				cur = cur->_left;
//		}
//
//		cur = new Node(val);
//		if (parent->_value.first < val.first)
//			parent->_right = cur;
//		else
//			parent->_left = cur;
//
//		cur->_parent = parent;
//
//		//������ �޸���ɫ, ��ת
//		while (cur != _header->_parent && cur->_parent->_color == RED)
//		{
//			Node* p = cur->_parent;
//			Node* g = p->_parent;
//			if (g->_left == p)
//			{
//				Node* u = g->_right;
//				if (u && u->_color == RED)
//				{
//					//�޸���ɫ
//					u->_color = p->_color = BLACK;
//					g->_color = RED;
//					//�������ϲ鿴
//					cur = g;
//				}
//				else
//				{
//					//u������/u������Ϊ��
//					if (cur == p->_right)
//					{
//						RotateL(p);
//						swap(cur, p);
//					}
//					//cur��p�����,����
//					RotateR(g);
//					//�޸���ɫ
//					p->_color = BLACK;
//					g->_color = RED;
//
//					break;
//				}
//			}
//			else
//			{
//				Node* u = g->_left;
//				if (u && u->_color == RED)
//				{
//					//�޸���ɫ
//					u->_color = p->_color = BLACK;
//					g->_color = RED;
//					//�������ϲ鿴
//					cur = g;
//				}
//				else
//				{
//					//u������/u������Ϊ��
//					if (cur == p->_left)
//					{
//						RotateR(p);
//						swap(cur, p);
//					}
//					//cur��p�����,����
//					RotateL(g);
//					//�޸���ɫ
//					p->_color = BLACK;
//					g->_color = RED;
//
//					break;
//				}
//			}
//		}
//
//		//����ɫ��Ϊ��ɫ
//		_header->_parent->_color = BLACK;
//		//����_header������
//		_header->_left = leftMost();
//		_header->_right = rightMost();
//		return true;
//	}
//
//	Node* leftMost()
//	{
//		Node* cur = _header->_parent;
//		while (cur && cur->_left)
//			cur = cur->_left;
//		return cur;
//	}
//
//	Node* rightMost()
//	{
//		Node* cur = _header->_parent;
//		while (cur && cur->_right)
//			cur = cur->_right;
//		return cur;
//	}
//
//	void RotateR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
//
//		subL->_right = parent;
//		parent->_left = subLR;
//
//		if (subLR)
//			subLR->_parent = parent;
//
//		if (parent == _header->_parent)
//		{
//			_header->_parent = subL;
//			subL->_parent = _header;
//		}
//		else
//		{
//			Node* g = parent->_parent;
//			subL->_parent = g;
//			if (g->_left == parent)
//				g->_left = subL;
//			else
//				g->_right = subL;
//		}
//
//		parent->_parent = subL;
//
//	}
//
//	void RotateL(Node* parent)
//	{
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//
//		subR->_left = parent;
//		parent->_right = subRL;
//
//		if (subRL)
//			subRL->_parent = parent;
//
//		if (parent == _header->_parent)
//		{
//			_header->_parent = subR;
//			subR->_parent = _header;
//		}
//		else
//		{
//			Node* g = parent->_parent;
//			subR->_parent = g;
//			if (g->_left == parent)
//				g->_left = subR;
//			else
//				g->_right = subR;
//		}
//		parent->_parent = subR;
//
//	}
//
//	void inorder()
//	{
//		_inorder(_header->_parent);
//		cout << endl;
//	}
//	void _inorder(Node* root)
//	{
//		if (root)
//		{
//			_inorder(root->_left);
//			cout << root->_value.first << " ";
//			_inorder(root->_right);
//		}
//	}
//
//	bool isRBtree()
//	{
//		Node* root = _header->_parent;
//		if (root == nullptr)
//			return true;
//		//1. ���Ƿ�Ϊ��ɫ
//		if (root->_color != BLACK)
//			return false;
//
//		//2. ÿ��·����ɫ�Ƿ���ͬ�� 3. ��ɫ�Ƿ�����
//		//��ȡĳһ��·���Ϻ�ɫ��������Ϊ��׼ֵ
//		int blackCount = 0;
//		Node* cur = root;
//		while (cur)
//		{
//			if (cur->_color == BLACK)
//				++blackCount;
//			cur = cur->_left;
//		}
//
//		int curCount = 0;
//		//����
//		return _isRBTree(root, blackCount, curCount);
//	}
//
//	bool _isRBTree(Node* root, int blackCount, int curCount)
//	{
//		//��ǰ·���Ϻ�ɫ�����Ƿ���ͬ
//		if (root == nullptr)
//		{
//			if (blackCount != curCount)
//				return false;
//			return true;
//		}
//
//		//�����ǰ�ڵ�Ϊ��ɫ���ۼ�
//		if (root->_color == BLACK)
//			++curCount;
//
//		Node* parent = root->_parent;
//		if (parent && parent->_color == RED && root->_color == RED)
//		{
//			//cout << "�к�ɫ�����Ľڵ�" << endl;
//			return false;
//		}
//
//		return _isRBTree(root->_left, blackCount, curCount)
//			&& _isRBTree(root->_right, blackCount, curCount);
//	}
//
//private:
//	Node* _header;
//};
//
//void testRBTree()
//{
//	int array[] = { 10, 2, 4, 5, 8, 9, 3, 0 };
//	RBTree<int, int> rbt;
//	for (const auto& e : array)
//	{
//		rbt.insert(make_pair(e, e));
//	}
//	rbt.inorder();
//	cout << "�Ƿ�Ϊ�������" << rbt.isRBtree() << endl;
//}
//
//void testRBTree2()
//{
//	srand(time(nullptr));
//	RBTree<int, int> rbt;
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		int num = rand();
//		rbt.insert(make_pair(num, num));
//	}
//	//rbt.inorder();
//	cout << "�Ƿ�Ϊ�������" << rbt.isRBtree() << endl;
//}
//
////int main()
////{
////	//testRBTree();
////	testRBTree2();
////	return 0;
////}