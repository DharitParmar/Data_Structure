
const int maxqueue = 5;
class int_garage
{
public:
	int q_array[6];
	int front;
	int rear;

	bool empty_q();
	void clear_q();
	void insert_q(int numb);
	void delete_q(int& numb);
	bool full_q();
};

bool int_garage::empty_q()
{
	if (rear == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void int_garage::clear_q()
{
	front = maxqueue;
	rear = maxqueue;
}

bool int_garage::full_q()
{
	int q_rear;
	if (rear == maxqueue)
	{
		q_rear = 0;
	}
	else
	{
		q_rear = rear + 1;
	}
	if (q_rear == front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void int_garage::insert_q(int numb)
{
	if (rear == maxqueue)
	{
		rear = 0;
	}
	else
	{
		rear = rear + 1;
	}
	q_array[rear] = numb;
}

void int_garage::delete_q(int& numb)
{
	if (front == maxqueue)
	{
		front = 0;
	}
	else
	{
		front = front + 1;
	}
	numb = q_array[front];
}