# Type casting

## Casting types:

- C-style casts;

- static casts;

- const casts;

- dynamic casts;

- reinterpret casts.


## static_cast

```
	char c { 'a' };
	std::cout << c << ' ' << static_cast<int>(c) << '\n'; // prints a 97
```

- best when you need to convert a value from one type to another type;

- provides compile-time type checking, making it harder to make an inadvertent error;

- less powerful than C-style casts, so you can’t inadvertently remove const or do other things you may not have intended to do.


## Overloading typecasts

```
	class Centimeter {
		private:
			int m_centimeters;

		public:
			Centimeter(int centimeters = 0) : m_centimeters(centimeters) {

			}

    		// Overloaded int cast
    		operator int() const { 
    			return m_centimeters;
    		}
	};
```

```
	Centimeter centimeters(7);
	int c = static_cast<int>(centimeters);
```

```
	class Meter {
		private:
    		int m_meters;
		public:
    		Meter(int meters = 0) : m_meters(meters) {

    		}

     		// Allow us to convert Meter into Centimeter
     		operator Centimeter() const { return Centimeter{ m_meters * 1000 }; }
};
```

```
	void printCentimeters(Centimeter centimeters) {
	    std::cout << centimeters; // centimeters will be implicitly cast to an int
	}
```


## dynamic_cast

- <b> downcasting </b> - converting base-class pointers into derived-class pointers;

- if a dynamic_cast fails, the result of the conversion will be a null pointer;

- downcasting with static_cast;


# Задачи:

## Задача 1:
Направете клас Apartment, който съдържа следните данни: име на собственик, номер на сградата, вход, етаж, брой на живущите.

## Задача 2:
Направете клас Building, който съдържа следните данни: номер на сградата, списък от тип Apartment.

## Задача 3:
Напишете функция, която принтира броя на живущите в даден апартамент.

## Задача 4:
Напишете функция, която принтира броя на живущите в даден сграда.