#pragma once

#include <string>
#include <any>

namespace nf {
    class INotifyDataChanging;

    class IPropertyChangingListener {
    public:
        virtual bool onPropertyChanging(INotifyDataChanging* object, const std::string& propertyName, const std::any& oldValue, const std::any& newValue) = 0;

        virtual ~IPropertyChangingListener() = default;
    };
}