 #include"Forward_list.h"

void main()
{
	size_t n;
	cout << "Input size >> ";
	cin >> n;
	int value;
	size_t index = 5;
	char choise;
	ForwardList<int> list;
	for (size_t i = 0; i < n; i++)
	{
		list.push_front(rand() % 30 + 5);
	}
	do
	{
		system("cls");
		list.print();
		cout << "\n\nWhat operation do you want to do:\n\t1.push_back\n\t2.push_front\n\t3.pop_back"
			<< "\n\t4.pop_front\n\t5.insert\n\t6.erase\n\t7.clear\n\t8.Set Element\n >> ";

		choise = _getch();

		if (choise == '1' || choise == '2' || choise == '5' || choise == '8')
		{
			cout << "\nEnter value >> ";  cin >> value;
		}
		if (choise == '6' || choise == '5' || choise == '8')
		{
			cout << "\nEneter index >> "; cin >> index;
		}

		switch (choise)
		{
		case '1': list.push_back(value); break;
		case '2': list.push_front(value); break;
		case '3': list.pop_back(); break;
		case '4': list.pop_front(); break;
		case '5': list.insert(index, value); break;
		case '6': list.erase(index); break;
		case '7': list.clear(); break;
		case '8': list.set_element(index, value); break;
		case 'q': return;
		}

	} while (true);

}