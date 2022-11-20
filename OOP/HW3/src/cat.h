#include <string>

class Cat {
public:

  Cat(std::string name, double weight) {
    this->_name=name;
    this->_weight=weight;
    this->_toyAmount=0;
    this->_toyCollections=nullptr;
  }

  ~Cat() {
    delete[] this->_toyCollections;
  }

  std::string getName() {
    return this->_name;
  }

  double getWeight() {
    return this->_weight;
  }

  void addNewToy(std::string toyName) {
    if (this->_toyAmount==0){
      this->_toyCollections=new std::string[1];
      this->_toyCollections[0]=toyName;
      this->_toyAmount+=1;
    }
    else {
      this->_toyAmount+=1;
      std::string *A = new std::string[this->_toyAmount];
      for(int i =0 ; i < this->_toyAmount-1 ; i++){
        A[i]=this->_toyCollections[i];
      }
      A[this->_toyAmount-1] = toyName;
      delete[] this->_toyCollections;
      this->_toyCollections = A;
    }
  }

  std::string getToy(int index) {
    return this->_toyCollections[index];
  }

private:
  std::string _name;
  double _weight;
  std::string * _toyCollections;
  int _toyAmount;

};
