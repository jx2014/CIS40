size_t GetSpeed();
size_t GetMinSpeed();
size_t GetMaxSpeed();
void SetSpeed();
void SetSpeed(size_t s);
//void MenuSelection(); //use new int MenuSelection() to return a value after select an item
int MenuSelection();
void DisplayMenu();
void GetSelection();
void ImplementSelection();
bool CheckContinue();
void SelectModel();
void DisplayModelMenu();
void GetModelSelection();

// below functions are from lab 4.
void DefaultSetSpeed(size_t s = 20);
void Swap(size_t &a, size_t &b);
void DistanceTravelled(size_t x);
void GetSelectedSpeed();
