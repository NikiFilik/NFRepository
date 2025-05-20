#include "AuthService.hpp"

namespace nf {
    void AuthService::loadAuth() {
        std::ifstream file;
        file.exceptions(std::ifstream::badbit);

        try {
            file.open(this->authFileName);

            if (file.eof()) {
                return;
            }

            json j;
            file >> j;
            if (j.contains("id") && j["id"] != "null") {
                int user_id = j["id"];
                this->currentUser = repository.getById(j["id"]);

                if (!currentUser) {
                    std::cout << "Stored user ID " << user_id << " not found in repository\n";
                }
            }
        }

        catch (const std::ifstream::failure& e) {
            std::cerr << "File error: " << e.what() << std::endl;
            throw;
        }

        catch (const json::exception& e) {
            std::cerr << "JSON error: " << e.what() << std::endl;
            throw;
        }

        catch (const std::exception& e) {
            std::cerr << "Common error: " << e.what() << std::endl;
            throw;
        }
    }

    void AuthService::saveAuth() const {
        json j;

        if (currentUser) {
            j["id"] = currentUser->id;
        }
        else {
            j["id"] = "null";
        }

        std::ofstream file;
        file.exceptions(std::ofstream::badbit);

        try {
            file.open(this->authFileName);
            file << j.dump(0);
        }
        catch (const std::ofstream::failure& fail) {
            std::cout << fail.what() << '\n';
        }

        file.close();
    }

    AuthService::AuthService(nf::DataRepository<nf::User>& repository, const std::string& authFileName) : repository(repository), authFileName(authFileName) {
        loadAuth();
    }

    void AuthService::signIn(const User& user) {
        currentUser = repository.getById(user.id);
        saveAuth();
    }

    void AuthService::signOut() {
        currentUser = nullptr;
        saveAuth();
    }

    bool AuthService::isAuthorized() {
        return currentUser != nullptr;
    }

    nf::User AuthService::getCurrentUser() {
        if (!currentUser) {
            throw std::runtime_error("Not authorized");
        }
        return *currentUser;
    }
}