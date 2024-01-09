#include <iostream>

void	putst(std::string temp)
{
	std::cout << " | ";
	if (temp.size() > 10)
	{
		temp.resize(9);
		std::cout << temp;
		std::cout << ".";
	}
	else
		std::cout << temp;
}

int	is_valid_imput(std::string imput, int flag)
{
	if (imput.size() > 30)
		return (0);
	if (flag == 1)
	{
		for (int i = 0; i < (int)imput.size(); i++)
		{
			if (!(isdigit(imput[i])))
				return(0);
		}
	}
	return(1);
}

class Contacts{
private:
	int id;
	std::string fname;
	std::string lname;
	std::string nickname;
	std::string number;
	std::string secret;
public:
	void	setValue(std::string type, std::string value)
	{
		if (type == "fname")
			fname = value;
		else if (type == "lname")
			lname = value;
		else if (type == "nickname")
			nickname = value;
		else if (type == "number")
			number = value;
		else if (type == "secret")
			secret = value;
		else
			return;
	}
	void	printvalue()
	{
		std::cout << id;
		putst(fname);
		putst(lname);
		putst(nickname);
		putst(number);
		putst(secret);
		std::cout << std::endl;
	};
	void	printcontact()
	{
		std::cout << "First name: " << fname << std::endl;
		std::cout << "last name: " << lname << std::endl;
		std::cout << "nickname: " << nickname << std::endl;
		std::cout << "number: " << number << std::endl;
		std::cout << "darkest secret: " << secret << std::endl;
	}
	void	setid(int num)
	{
		id = num;
	}
};

class Phonebook{
private:
	Contacts contact[8];
	int id;
	int fid;
public:
	void	AddContact()
	{
		std::string buf;
		if (id == 8)
			id = 0;
		contact[id].setid(id);
		while(1)
		{
			std::cout << "First name: ";
			std::cin >> buf;
			if (is_valid_imput(buf, 0))
				break;
			else
				std::cout << "wrong format for first name, try again..." << std::endl;
		}
		contact[id].setValue("fname", buf);

		while(1)
		{
			std::cout << "Last name: ";
			std::cin >> buf;
			if (is_valid_imput(buf, 0))
				break;
			else
				std::cout << "wrong format for last name, try again..." << std::endl;
		}
		contact[id].setValue("lname", buf);

		while(1)
		{
			std::cout << "Nickname: ";
			std::cin >> buf;
			if (is_valid_imput(buf, 0))
				break;
			else
				std::cout << "wrong format for nickname, try again..." << std::endl;
		}
		contact[id].setValue("nickname", buf);

		while(1)
		{
			std::cout << "Number: ";
			std::cin >> buf;
			if (is_valid_imput(buf, 1))
				break;
			else
				std::cout << "wrong format for number, try again..." << std::endl;
		}
		contact[id].setValue("number", buf);

		while(1)
		{
			std::cout << "darkest secret: ";
			std::cin >> buf;
			if (is_valid_imput(buf, 0))
				break;
			else
				std::cout << "wrong format for secret, try again..." << std::endl;
		}
		contact[id].setValue("secret", buf);
		id++;
		fid = id;
		if (id == 8)
			fid = 8;
	};
	void	Search()
	{
		int buf;
		std::cout << "Availiable contacts, choose a id number: " << std::endl;
		for (int i = 0; i < fid; i++)
			contact[i].printvalue();
		std::cin >> buf;
		if (buf > -1 && buf < 9)
			contact[buf].printcontact();
		return;
	};
};


int main(void)
{
	Phonebook phonebook;
	std::string buffer;
	std::cout << "welcome to your phonebook!" << std::endl;
	while (1)
	{
		std::cin >> buffer;
		if (buffer == "ADD")
			phonebook.AddContact();
		else if (buffer == "SEARCH")
			phonebook.Search();
		else if (buffer == "EXIT")
			break;
		else
		{
			std::cout << "Wrong command, you can try ADD, SEARCH or EXIT" << std::endl;
			continue;
		}
	}
	return(0);
}
