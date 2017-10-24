
#include <string>
using namespace std;
const int maxqueue = 5;
class char_garage
{
public:
string q_array[6];
int front_ch;
int rear_ch;

bool empty_q();
void clear_q();
void insert_q(string numb)
{
if (rear_ch == maxqueue)
{
	rear_ch = 0;
}
else
{
	rear_ch = rear_ch + 1;
}
	q_array[rear_ch] = numb;
}

void delete_q(string& numb)
{
	if (front_ch == maxqueue)
{
	front_ch = 0;
}
else
{
	front_ch = front_ch + 1;
}
	numb = q_array[front_ch];
}

bool full_q();
};	//??????????????????

bool char_garage::empty_q()
{
	if (rear_ch == front_ch)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void char_garage::clear_q()
{
	front_ch = maxqueue;
	rear_ch = maxqueue;
}

bool char_garage::full_q()
{
	int q_rear;
	if (rear_ch == maxqueue)
	{
		q_rear = 0;
	}
	else
	{
		q_rear = rear_ch + 1;
	}
	if (q_rear == front_ch)
	{
		return true;
	}
	else
	{
		return false;
	}
}