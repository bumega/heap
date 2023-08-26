#include <iostream>
#include <vector>


class heap {
public:
    heap() {
        vec = {0};
    }



    void add(int el) {
        vec.push_back(el);
        int ind = vec.size() - 1;
        while (ind != 1 and vec[ind] > vec[parent(ind)]) {
            std::swap(vec[ind], vec[parent(ind)]);
            ind = parent(ind);
        }
    }



    void del(int ind) {
        std::swap(vec[ind], vec[vec.size() - 1]);
        vec.erase(vec.begin() + vec.size() - 1);
        check(ind);
    }




    void output() {
        for (auto i : vec) {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }

    void form(std::vector<int>&& v_p) {
        vec = std::move(v_p);
        vec.insert(vec.begin(), 0);
        for (int i = vec.size() / 2; i > 0; i--) {
            check(i);
        }
    }


    ~heap() = default;
private:


    int parent(int i) {
        return i / 2;
    }

    int left(int i) {
        if (i * 2 < vec.size()) {
            return i * 2;
        } else {
            return 0;
        }
    }

    int right(int i) {
        if ((i * 2) + 1 < vec.size()) {
            return (i * 2) + 1;
        } else {
            return 0;
        }
    }

    void check(int ind) {
        if (vec[left(ind)] > vec[ind] or vec[right(ind)] > vec[ind]) {
            if (vec[left(ind)] > vec[right(ind)]) {
                std::swap(vec[left(ind)], vec[ind]);
                check(vec[left(ind)]);
            } else {
                std::swap(vec[right(ind)], vec[ind]);
                check(vec[right(ind)]);
            }
        }
    }



    std::vector<int> vec;
};



int main() {
    heap H;
    std::vector<int> vvv = {3, 4, 5, 8, 11, 1, 16, 2};
    H.form(std::move(vvv));
    H.output();
    return 0;
}
