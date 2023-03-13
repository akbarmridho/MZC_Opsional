#include "AbilityStatus.hpp"
#include "../exception/AbilitiesException.hpp"

AbilityStatus::AbilityStatus(string name) : name(std::move(name)), used(false), deactivated(false)
{
}

bool AbilityStatus::getUsed() const
{
  return used;
}

string AbilityStatus::getName() const
{
  return name;
}

bool AbilityStatus::isDeactivated() const
{
  return this->deactivated;
}

void AbilityStatus::deactivate()
{
  this->deactivated = true;
}

void AbilityStatus::setUsed()
{
  this->used = true;
}

void AbilityStatus::notUsedOrThrow() const
{
  if (this->getUsed())
  {
    throw UsedCardException(this->getName());
  }
}

void AbilityStatus::activeOrThrow() const
{
  if (this->isDeactivated())
  {
    throw DeactivatedCardException(this->getName());
  }
}

void AbilityStatus::haveOrThrow(string name) const
{
  if (this->name != name)
  {
    throw NotOwnedCardException(this->getName());
  }
}