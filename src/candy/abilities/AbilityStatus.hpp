#ifndef ABILITYSTATUS_HPP
#define ABILITYSTATUS_HPP
#include <string>
using std::string;

class AbilityStatus
{
private:
  bool used;
  bool deactivated;
  string name;

public:
  AbilityStatus(string);

  [[nodiscard]] bool getUsed() const;
  [[nodiscard]] bool isDeactivated() const;
  [[nodiscard]] string getName() const;

  void setUsed();
  void deactivate();

  void notUsedOrThrow() const;
  void activeOrThrow() const;
  void haveOrThrow(string) const;
};

#endif