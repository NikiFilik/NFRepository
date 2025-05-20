#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "User.hpp"
#include "DataRepository.hpp"
#include "AuthService.hpp"

int main() {
    nf::DataRepository<nf::User> userRepo("users.json");
    nf::AuthService auth(userRepo, "auth.json");


    nf::User user1(1, "Nikita", "NikiFilik", "COOL_PASSWORD");
    userRepo.add(user1);
    
    if (userRepo.getByLogin(user1.login)) {
        auth.signIn(user1);
        std::cout << "Logged in: " << auth.getCurrentUser() << "\n";
    }

    std::cout << "Authorized: " << (auth.isAuthorized() ? "Yes" : "No") << "\n\n\n";



    nf::User user2(2, "Sasha", "Tut-Turuu", "qwerty");
    userRepo.add(user2);

    if (userRepo.getByLogin(user2.login)) {
        auth.signIn(user2);
        std::cout << "New user: " << auth.getCurrentUser() << "\n";
    }

    auth.signOut();
    std::cout << "After logout: " << (auth.isAuthorized() ? "Yes" : "No") << "\n\n\n";


    
    if (userRepo.getByLogin(user1.login)) {
        auth.signIn(user1);
    }
    
    nf::AuthService newAuth(userRepo, "auth.json");
    
    std::cout << "Current user after restart: " << auth.getCurrentUser() << "\n\n\n";
    
	return 0;
}
