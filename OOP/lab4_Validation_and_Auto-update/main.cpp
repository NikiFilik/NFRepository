#include <iostream>
#include <vector>
#include <algorithm>
#include <any>
#include <string>
#include <memory>

// 1. Шаблонный интерфейс слушателя изменений
template <typename T>
class IPropertyChangedListener {
public:
    virtual void on_property_changed(T* obj, const std::string& property_name) = 0;

    virtual ~IPropertyChangedListener() = default;
};

// 2. Интерфейс для управления слушателями (не шаблонный)
class INotifyDataChanged {
public:
    virtual void add_property_changed_listener(IPropertyChangedListener<INotifyDataChanged>* listener) = 0;
    virtual void remove_property_changed_listener(IPropertyChangedListener<INotifyDataChanged>* listener) = 0;

    virtual ~INotifyDataChanged() = default;
};

// 4. Шаблонный интерфейс валидатора
template <typename T>
class IPropertyChangingListener {
public:
    virtual bool on_property_changing(T* obj, const std::string& property_name, const std::any& old_value, const std::any& new_value) = 0;

    virtual ~IPropertyChangingListener() = default;
};

// 5. Интерфейс для управления валидаторами (не шаблонный)
class INotifyDataChanging {
public:
    virtual void add_property_changing_listener(IPropertyChangingListener<INotifyDataChanging>* listener) = 0;
    virtual void remove_property_changing_listener(IPropertyChangingListener<INotifyDataChanging>* listener) = 0;

    virtual ~INotifyDataChanging() = default;
};

// 3,6. Основной наблюдаемый класс
class ObservableClass :
    public INotifyDataChanged,
    public INotifyDataChanging {

    std::vector<IPropertyChangedListener<INotifyDataChanged>*> changed_listeners;
    std::vector<IPropertyChangingListener<INotifyDataChanging>*> changing_listeners;

    std::string name;
    int age = 0;

public:
    // Управление слушателями изменений
    void add_property_changed_listener(
        IPropertyChangedListener<INotifyDataChanged>* listener
    ) override {
        changed_listeners.push_back(listener);
    }

    void remove_property_changed_listener(
        IPropertyChangedListener<INotifyDataChanged>* listener
    ) override {
        auto it = std::find(changed_listeners.begin(), changed_listeners.end(), listener);
        if (it != changed_listeners.end()) changed_listeners.erase(it);
    }

    // Управление валидаторами
    void add_property_changing_listener(
        IPropertyChangingListener<INotifyDataChanging>* listener
    ) override {
        changing_listeners.push_back(listener);
    }

    void remove_property_changing_listener(
        IPropertyChangingListener<INotifyDataChanging>* listener
    ) override {
        auto it = std::find(changing_listeners.begin(), changing_listeners.end(), listener);
        if (it != changing_listeners.end()) changing_listeners.erase(it);
    }

    // Сеттеры с валидацией
    void set_name(const std::string& new_name) {
        if (name == new_name) return;

        const std::any old_value = name;
        const std::any new_value = new_name;

        bool validation_passed = true;
        for (auto listener : changing_listeners) {
            if (!listener->on_property_changing(this, "name", old_value, new_value)) {
                validation_passed = false;
                break;
            }
        }

        if (validation_passed) {
            name = new_name;
            for (auto listener : changed_listeners) {
                listener->on_property_changed(this, "name");
            }
        }
    }

    void set_age(int new_age) {
        if (age == new_age) return;

        const std::any old_value = age;
        const std::any new_value = new_age;

        bool validation_passed = true;
        for (auto listener : changing_listeners) {
            if (!listener->on_property_changing(this, "age", old_value, new_value)) {
                validation_passed = false;
                break;
            }
        }

        if (validation_passed) {
            age = new_age;
            for (auto listener : changed_listeners) {
                listener->on_property_changed(this, "age");
            }
        }
    }

    // Геттеры
    std::string get_name() const { return name; }
    int get_age() const { return age; }
};

// Валидатор возраста
class AgeValidator : public IPropertyChangingListener<INotifyDataChanging> {
public:
    bool on_property_changing(
        INotifyDataChanging* obj,
        const std::string& property_name,
        const std::any& old_value,
        const std::any& new_value
    ) override {
        if (property_name != "age") return true;

        try {
            int new_age = std::any_cast<int>(new_value);
            if (new_age < 0 || new_age > 150) {
                std::cout << "[AgeValidator] Invalid age: " << new_age << "\n";
                return false;
            }
            return true;
        }
        catch (const std::bad_any_cast&) {
            std::cout << "[AgeValidator] Type error!\n";
            return false;
        }
    }
};

// Валидатор имени
class NameValidator : public IPropertyChangingListener<INotifyDataChanging> {
public:
    bool on_property_changing(
        INotifyDataChanging* obj,
        const std::string& property_name,
        const std::any& old_value,
        const std::any& new_value
    ) override {
        if (property_name != "name") return true;

        try {
            auto new_name = std::any_cast<std::string>(new_value);
            if (new_name.empty()) {
                std::cout << "[NameValidator] Name cannot be empty!\n";
                return false;
            }
            return true;
        }
        catch (const std::bad_any_cast&) {
            std::cout << "[NameValidator] Type error!\n";
            return false;
        }
    }
};

// Логгер изменений
class Logger : public IPropertyChangedListener<INotifyDataChanged> {
public:
    void on_property_changed(
        INotifyDataChanged* obj,
        const std::string& property_name
    ) override {
        ObservableClass* observable = dynamic_cast<ObservableClass*>(obj);
        if (!observable) return;

        if (property_name == "name") {
            std::cout << "[Logger] Name changed to: "
                << observable->get_name() << "\n";
        }
        else if (property_name == "age") {
            std::cout << "[Logger] Age changed to: "
                << observable->get_age() << "\n";
        }
    }
};

int main() {
    ObservableClass person;

    auto age_validator = std::make_unique<AgeValidator>();
    auto name_validator = std::make_unique<NameValidator>();
    auto logger = std::make_unique<Logger>();

    person.add_property_changing_listener(age_validator.get());
    person.add_property_changing_listener(name_validator.get());
    person.add_property_changed_listener(logger.get());

    // Корректные изменения
    person.set_name("Alice");
    person.set_age(25);

    // Некорректные данные
    person.set_name("");
    person.set_age(-5);

    // Дополнительные корректные изменения
    person.set_age(30);
    person.set_name("Bob");

    return 0;
}