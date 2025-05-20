#pragma once

#include "IDataRepository.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json.hpp"

namespace nf {
    template <typename T>
    class DataRepositoryCommonFunctionality : public nf::IDataRepositoryCommonFunctionality<T> {
    protected:
        std::string fileName;
        std::vector<T> data;

        void loadData() {
            std::ifstream file;
            file.exceptions(std::ifstream::badbit);

            try {
                file.open(this->fileName);

                if (file.eof()) {
                    this->data.clear();
                    return;
                }

                json j;
                file >> j;
                this->data.clear();
                for (const auto& item : j) {
                    this->data.push_back(T::fromJson(item));
                }
            }

            catch (const std::ifstream::failure& e) {
                std::cerr << "File error: " << e.what() << std::endl;
                throw;
            }

            catch (const json::exception& e) {
                std::cerr << "JSON error: " << e.what() << std::endl;
                this->data.clear();
                throw;
            }

            catch (const std::exception& e) {
                std::cerr << "Common error: " << e.what() << std::endl;
                throw;
            }

            file.close();
        }

        void saveData() {
            json j = json::array();

            for (const auto& item : this->data) {
                j.push_back(item.toJson());
            }

            std::ofstream file;
            file.exceptions(std::ofstream::badbit);

            try {
                file.open(this->fileName);
                file << j.dump(0);
            }
            catch (const std::ofstream::failure& fail) {
                std::cout << fail.what() << '\n';
            }

            file.close();
        }

    public:
        DataRepositoryCommonFunctionality(const std::string& fileName) : fileName(fileName) {
            loadData();
        }

        std::vector<T> getAll() override {
            return this->data;
        }

        T* getById(int id) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [id](const T& object) { return object.id == id; });

            if (iter == data.end()) {
                return nullptr;
            }

            return &(*iter);
        }

        void add(const T& object) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [&object](const T& obj) { return obj.id == object.id; });

            if (iter != this->data.end()) {
                std::cout << "Object id " << object.id << " already in repository\n";
                return;
            }

            this->data.push_back(object);
            saveData();
        }

        void update(const T& object) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [&object](const T& obj) { return obj.id == object.id; });

            if (iter == this->data.end()) {
                return;
            }

            *iter = object;
            saveData();
        }

        void remove(const T& object) override {
            auto iter = std::find(this->data.begin(), this->data.end(), object);

            if (iter == this->data.end()) {
                return;
            }

            this->data.erase(iter);
            saveData();
        }
    };

    template <typename T>
	class DataRepository : public nf::DataRepositoryCommonFunctionality<T>, public nf::IDataRepository<T> {
    public:
        DataRepository(const std::string& fileName) : DataRepositoryCommonFunctionality<T>(fileName) {

        }

        std::vector<T> getAll() override {
            return nf::DataRepositoryCommonFunctionality<T>::getAll();
        }
        T* getById(int id) override {
            return nf::DataRepositoryCommonFunctionality<T>::getById(id);
        }
        void add(const T& object) override {
            nf::DataRepositoryCommonFunctionality<T>::add(object);
        }
        void update(const T& object) override {
            nf::DataRepositoryCommonFunctionality<T>::update(object);
        }
        void remove(const T& object) override {
            nf::DataRepositoryCommonFunctionality<T>::remove(object);
        }
	};

    template <>
    class DataRepository<nf::User> : public nf::DataRepositoryCommonFunctionality<nf::User>, public nf::IDataRepository<nf::User> {
    public:
        DataRepository(const std::string& fileName) : DataRepositoryCommonFunctionality<nf::User>(fileName) {

        }

        std::vector<nf::User> getAll() override {
            return nf::DataRepositoryCommonFunctionality<nf::User>::getAll();
        }
        nf::User* getById(int id) override {
            return nf::DataRepositoryCommonFunctionality<nf::User>::getById(id);
        }
        void add(const nf::User& object) override {
            nf::DataRepositoryCommonFunctionality<nf::User>::add(object);
        }
        void update(const nf::User& object) override {
            nf::DataRepositoryCommonFunctionality<nf::User>::update(object);
        }
        void remove(const nf::User& object) override {
            nf::DataRepositoryCommonFunctionality<nf::User>::remove(object);
        }

        nf::User* getByLogin(std::string login) {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [login](const nf::User& object) { return object.login == login; });

            if (iter == data.end()) {
                return nullptr;
            }

            return &(*iter);
        }
    };
}