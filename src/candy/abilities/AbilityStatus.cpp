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
  if (this->getUsed())
  {
    throw DeactivatedCardException(this->getName());
  }
}