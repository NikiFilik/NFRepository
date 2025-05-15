#pragma once

#include "IDataRepository.hpp"

#include <fstream>

namespace nf {
    template <typename T>
	class DataRepository : public IDataRepository<T> {
    protected:
        std::string filename;
        std::vector<T> data;

        //BLIN BLINSKY NEDODELANO
        void loadData() {

        }

        void saveData() {

        }

    public:
        DataRepository(const std::string& filename) : filename(filename) {
            loadData();
        }

        std::vector<T> getAll() override {
            return this->data;
        }

        T* getById(int id) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [id] (const T& object) { return object.id == id; });

            if (iter == data.end()) {
                return nullptr;
            }

            return &(*iter);
        }

        void add(const T& object) override {
            this->data.push_back(object);
            saveData();
        }

        void update(const T& object) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [&object] (const T& obj) { return obj.id == object.id; });

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



    template <>
    class DataRepository<nf::User> : public IDataRepository<nf::User> {
    protected:
        std::string filename;
        std::vector<T> data;

        //BLIN BLINSKY NEDODELANO
        void loadData() {

        }

        void saveData() {

        }

    public:
        DataRepository(const std::string& filename) : filename(filename) {
            loadData();
        }

        std::vector<nf::User> getAll() override {
            return this->data;
        }

        nf::User* getById(int id) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [id](const nf::User& object) { return object.id == id; });

            if (iter == data.end()) {
                return nullptr;
            }

            return &(*iter);
        }

        void add(const nf::User& object) override {
            this->data.push_back(object);
            saveData();
        }

        void update(const nf::User& object) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [&object](const nf::User& obj) { return obj.id == object.id; });

            if (iter == this->data.end()) {
                return;
            }

            *iter = object;
            saveData();
        }

        void remove(const nf::User& object) override {
            auto iter = std::find(this->data.begin(), this->data.end(), object);

            if (iter == this->data.end()) {
                return;
            }

            this->data.erase(iter);
            saveData();
        }

        nf::User* getByLogin(std::string login) override {
            auto iter = std::find_if(this->data.begin(), this->data.end(), [login](const nf::User& object) { return object.login == login; });

            if (iter == data.end()) {
                return nullptr;
            }

            return &(*iter);
        }
    };
}