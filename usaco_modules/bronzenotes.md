# USACO Guide (Bronze)
Time limit for execution for usaco is 2 seconds.

## Some common runtimes
Mathematical formulas that just calculate an answer: $\mathcal{O}(1)$

Binary search: $\mathcal{O}(\log n)$

Ordered set/map or priority queue: $\mathcal{O}(\log n)$ per operation

Prime factorization of an integer, or checking primality or compositeness of
an integer naively: $\mathcal{O}(\sqrt{n})$

![Complexiities per n](imgs/possiblecomplexitiesforn.png)

Very handy formula for intersection of two lines (full real dumb right now)
```
calculate the answer by adding the original lengths and subtracting the
intersection length.
$$(b-a)+(d-c)-\text{intersection}([a,b],[c,d])$$
The
official analysis
splits computing the intersection length into several cases. However, we do it
more simply here. An interval $[x,x+1]$ is contained within both $[a,b]$ and
$[c,d]$ if $a\le x$, $c\le x$, $x, and $x. In other words,
$\max(a,c)\le x$ and $x<\min(b,d)$. So the length of the intersection is
$\min(b,d)-\max(a,c)$ if this quantity is positive and zero otherwise!
```

C++ has an array class as well as the normal array type. This class supports the standard empty() and size()
methods.

C++'s vector class is an example of a dynamic array like pythons list and stuff.

Couple different ways to iterate over elemnts of an array using iterators and the auto keyword
```c++
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {

	cout << *it << " "; //prints the values in the vector using the iterator

}
```
Using auto
```c++
vector<int> v{1,7,4,5,2};

for (auto it = begin(v); it != end(v); it = next(it)) {

	cout << *it << " "; //prints the values in the vector using the iterator

}
```

Vectors are still arrays so don't forget insertion or deletiong from the middle is *O(n)*.

## Strings
Read a full line of input using getline.
```c++

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin >> std::ws, age); // read a full line of text into age

    std::cout << "Your name is " << name << " and your age is " << age << '\n';

    return 0;
}
```
The `std::ws` is a input manipulator that tell cin to ignore leading whitespace.

## Pairs
We can use `make_pair(a,b)` to create a pair but we can also use `pair<int,int> = {a,b}` which is way easier to type.
