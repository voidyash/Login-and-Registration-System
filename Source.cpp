#include<iostream>
#include<fstream>
#include<sstream>

// login function
void login()
{
	std::string UserName, Password;
	std::string UserEnter, PassEnter;
	bool on_off = true;
	bool off = true;
	int count = 0;
	int left = 3; // chances left
	std::cout << "\n *******LOGIN TO YOUR ACCOUNT********" << std::endl;
	while (on_off)
	{
		std::fstream user;
		user.open("users.txt", std::ios::in);
		if (count < 3 && off && user.is_open())
		{
			if (count > 0)
			{
				std::cout << "\n Password or UserName is not correct" << std::endl;
				left--;
				std::cout << "You have *" << left << "* attempts left!" << std::endl;
			}
			std::cout << "Enter username:- " << std::endl;
			std::getline(std::cin, UserEnter);
			std::cout << "Enter password:- " << std::endl;
			std::getline(std::cin, PassEnter);
			count++;
			std::string read;

			while (std::getline(user, read))
			{
				std::stringstream converter(read);
				converter >> UserName >> Password;
				if (UserEnter == UserName && PassEnter == Password)
				{
					off = false;
				}
			}
		}
		else if (!off)
		{
			std::cout << "\n *** WELCOME!! ***" << std::endl;
			user.close();
			on_off = false;
		}
		else
		{
			std::cout << "TRY AGAIN LATER!!" << std::endl;
			user.close();
			on_off = false;
		}
	}
}

// registry function
void registry()
{
	std::string newName, checkName, newPass, confirmPass;
	int MiniPass;
	bool if_on = true;
	bool oo = true;

	std::cout << "\n ****CREATE NEW ACCOUNT****" << std::endl;

	// username validation
	while (oo)
	{
		std::cout << "Enter new username:- " << std::endl;
		std::getline(std::cin, newName);
		MiniPass = newName.length();

		std::fstream yusers;

		yusers.open("users.txt", std::ios::in);

		if (if_on && MiniPass >= 1 && yusers.is_open())
		{
			std::string readnew;
			while (std::getline(yusers, readnew))
			{
				std::stringstream OnlyUsers(readnew);
				OnlyUsers >> checkName;
				if (newName == checkName)
				{
					std::cout << "\n*" << newName << "* Username already exists! Try another one." << std::endl;
					if_on = false;
				}
			}
			yusers.close();
			if (!if_on)
			{
				if_on = true;
			}
			else
			{
				oo = false;
			}
		}
	}

	// password validation
	while (true)
	{
		std::cout << "Enter your new password:- " << std::endl;
		std::getline(std::cin, newPass);
		std::cout << "Confirm your new password:- " << std::endl;
		std::getline(std::cin, confirmPass);
		MiniPass = newPass.length();

		if (MiniPass > 8)
		{
			std::cout << "\n Your password is weak atleast 8 letters. " << std::endl;
		}
		else if (confirmPass == newPass)
		{
			std::fstream users;
			users.open("users.txt", std::ios::app);
			if (users.is_open())
			{
				users << newName + " " + newPass << std::endl;
				users.close();
			}
			std::cout << "\n==================================" << std::endl;
			std::cout << "\n SUCCESSFULLY NEW ACCOUNT CREATED" << std::endl << std::endl;
			std::cout << "\n==================================" << std::endl;
			break;
		}
		else
		{
			std::cout << "\n Password confirmation not correct" << std::endl;
		}
	}
	login();
}

int main()
{
	// user can choose login or register by just typing login or register
	std::string LoR;
	std::cout << "\n***** LOGIN or REGISTER *****" << std::endl << std::endl;
	std::cout << "================================" << std::endl;
	std::cout << "Please write (login) to LOGIN or (register) to REGISTER" << std::endl << std::endl;

	while (true)
	{
		std::getline(std::cin, LoR);
		if (LoR == "login")
		{
			login();
			break;
		}
		else if (LoR == "register")
		{
			registry();
			break;
		}
		else
		{
			std::cout << "\n Please write (login) and (register) correctly" << std::endl << std::endl;
		}
	}
	return 0;
}