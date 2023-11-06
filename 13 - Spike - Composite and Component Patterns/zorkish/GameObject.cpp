#include "GameObject.h"

string GameObject::GetName()
{
    return _name;
}

string GameObject::GetDesc()
{
    return _desc;
}

Component* GameObject::GetComponent(const string& name)
{
    auto iterator = _components.find(name);

    if (iterator == _components.end())
        return nullptr;
    else
        return iterator->second;
}

bool GameObject::AddComponent(Component* component)
{
    if (_components.find(component->GetName()) != _components.end())
        return false;

    _components[component->GetName()] = component;

    return true;
}

bool GameObject::RemoveComponent(const string& name)
{
    auto iterator = _components.find(name);

    if (iterator == _components.end())
        return false;

    _components.erase(iterator);

    return true;
}
