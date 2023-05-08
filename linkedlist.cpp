#include <iostream>;
using namespace std;
void main() {
	typedef int ElmenetType;
	typedef int Position;
	class List
	{
	private:
		ElmenetType* elements;
		int capacity;
		Position last;
	public:
		List(int n)
		{
			elements = new ElmenetType[n];
			capacity = n;
			last = -1;

		}
		void MakeNull()
		{
			last = -1;
		}
		Position END() {
			return last + 1;
		}
		void Insert(ElmenetType x, Position pos)
		{
			if (last == capacity - 1)
				cout << "list is full";
			else if (pos > last + 1 || pos < 0)
				cout << pos << ":pos is out of range" << last;
			else
			{
				for (Position i = last; i >= pos; i--)
				{
					elements[i + 1] = elements[i];
				}
				last++;
				elements[pos] = x;
			}
		}
		void Delete(Position pos)
		{
			if (pos > last || pos < 0)
				cout << "pos is out of range";

			for (Position i = pos + 1; i <= last; i++)
				elements[i - 1] = elements[i];
			last--;
		}
		Position Locate(ElmenetType x)
		{
			for (Position i = 0; i <= last; i++)
			{
				if ((x == elements[i]))
					return i;
			}
			return END();
		}
		ElmenetType Retrieve(Position pos)
		{
			if (pos > last || pos < 0)
			{
				cout << "pos is out of range"; return -1;
			}
			return elements[pos];
		}
		void PrintList()
		{
			for (Position i = 0; i <= last; i++)
			{
				cout << elements[i] << "-";
			}
			cout << endl;
		}
		Position First()
		{
			return 0;
		}
		Position Next(Position pos) {//you must write constrains here
			return pos + 1;
		}
		Position Previous(Position pos) {//you must write constrains here
			return pos - 1;
		}
		int Size()
		{
			return END();
		}
		void InsertXAfterY(ElmenetType x, ElmenetType y, List& l)
		{
			l.Insert(x, l.Next(l.Locate(y)));
		}
		void prug(List& l) {
			// prug remove the duplicate in the list 
			Position p, q;
			p = l.First();
			while (p != l.END()) {
				q = l.Next(p);
				while (q != l.END()) {
					if (l.Retrieve(p) == l.Retrieve(q)) {
						l.Delete(q);
					}
					else {
						q = l.Next(q);
					}
					p = l.Next(p);
				}
			}

		}
		void split(List l, List& odd, List& even) {
			Position test =l.First();
			while (test != l.END()) {
				ElmenetType x = l.Retrieve(test);
				if (x % 2 == 0) {
					even.Insert(x, even.END());
				}
				else {
					odd.Insert(x, odd.END());
				}
				test = l.Next(test);
			}
		}
		void conncatennet(List l1, List l2) {
			List l(l1.END() + l2.END());
			Position curr = l1.First();
			while (curr != l1.END()) {
				ElmenetType x = l1.Retrieve(curr);
				l.Insert(curr, l.END());
				curr = l1.Next(curr);
			}
			Position curr = l2.First();
			while (curr != l2.END()) {
				ElmenetType x = l2.Retrieve(curr);
				l.Insert(curr, l.END());
				curr = l2.Next(curr);
			}
			return l.PrintList();
		}
		ElmenetType Sum(List L)
		{
			Position curr = L.First();
			ElmenetType s = 0;
			while (curr != L.END())
			{
				ElmenetType x = L.Retrieve(curr);
				s = s + x;
				curr = L.Next(curr);
			}
			return s;
		}

	};
	
	













	system("pause");
}ظ