#pragma once


int TestInsertIntElementTree(int n) {
    auto tree1 = new BinaryTree<int>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestInsertDoubleElementTree(int n) {
    auto tree1 = new BinaryTree<double>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestInsertCharElementTree(int n) {
    auto tree1 = new BinaryTree<char>();

    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        tree1->Insert('a');
    }
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindIntElementTree(int n) {
    auto tree1 = new BinaryTree<int>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Find(n - 1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindDoubleElementTree(int n) {
    auto tree1 = new BinaryTree<double>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Find((n - 1) * 0.1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindCharElementTree(int n) {
    auto tree1 = new BinaryTree<char>();

    for (int i = 0; i < n; i++) {
        const char sim = randomRange('a', 'z');
        tree1->Insert(sim);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Find('z');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteIntElementTree(int n) {
    auto tree1 = new BinaryTree<int>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->DeleteElement(n - 1);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteDoubleElementTree(int n) {
    auto tree1 = new BinaryTree<double>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->DeleteElement(0.0);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestDeleteCharElementTree(int n) {
    auto tree1 = new BinaryTree<char>();

    for (int i = 0; i < n; i++) {
        const char sim = randomRange('a', 'z');
        tree1->Insert(sim);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->DeleteElement('a');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestGetIntSubTree(int n) {
    auto tree1 = new BinaryTree<int>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->GetSubTree(0);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestGetDoubleSubTree(int n) {
    auto tree1 = new BinaryTree<double>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->GetSubTree(0.0);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestGetCharSubTree(int n) {
    auto tree1 = new BinaryTree<char>();

    for (int i = 0; i < n; i++) {
        const char sim = randomRange('a', 'z');
        tree1->Insert(sim);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->GetSubTree('m');
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindIntSubtree(int n) {
    auto tree1 = new BinaryTree<int>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }

    BinaryTree<int>* tree2 = tree1;

    auto start_time = chrono::steady_clock::now();
    tree1->IsSubtree(tree2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindDoubleSubtree(int n) {
    auto tree1 = new BinaryTree<double>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }

    BinaryTree<double>* tree2 = tree1;

    auto start_time = chrono::steady_clock::now();
    tree1->IsSubtree(tree2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestFindCharSubtree(int n) {
    auto tree1 = new BinaryTree<char>();

    for (int i = 0; i < n; i++) {
        tree1->Insert('a');
    }

    BinaryTree<char>* tree2 = tree1;

    auto start_time = chrono::steady_clock::now();
    tree1->IsSubtree(tree2);
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestBalanceIntTree(int n) {
    auto tree1 = new BinaryTree<int>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Balance();
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestBalanceDoubleTree(int n) {
    auto tree1 = new BinaryTree<double>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Balance();
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestBalanceCharTree(int n) {
    auto tree1 = new BinaryTree<char>();

    for (int i = 0; i < n; i++) {
        const char sim = randomRange('a', 'z');
        tree1->Insert(sim);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Balance();
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestCloneIntTree(int n) {
    auto tree1 = new BinaryTree<int>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Clone();
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestCloneDoubleTree(int n) {
    auto tree1 = new BinaryTree<double>();

    for (int i = 0; i < n; i++) {
        tree1->Insert(i * 0.1);
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Clone();
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

int TestCloneCharTree(int n) {
    auto tree1 = new BinaryTree<char>();

    for (int i = 0; i < n; i++) {
        tree1->Insert('a');
    }

    auto start_time = chrono::steady_clock::now();
    tree1->Clone();
    auto end_time = chrono::steady_clock::now();
    int time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

    return time;
}

void TimeTestBinaryTree(int n) {
    PrintTimeTestResult("Insert int element", TestInsertIntElementTree(n));
    PrintTimeTestResult("Insert double element", TestInsertDoubleElementTree(n));
    PrintTimeTestResult("Insert char element", TestInsertCharElementTree(n));
    cout << endl;

    PrintTimeTestResult("Find int element", TestFindIntElementTree(n));
    PrintTimeTestResult("Find double element", TestFindDoubleElementTree(n));
    PrintTimeTestResult("Find char element", TestFindCharElementTree(n));
    cout << endl;

    PrintTimeTestResult("Delete int element", TestDeleteIntElementTree(n));
    PrintTimeTestResult("Delete double element", TestDeleteDoubleElementTree(n));
    PrintTimeTestResult("Delete char element", TestDeleteCharElementTree(n));
    cout << endl;

    PrintTimeTestResult("Get int subtree", TestGetIntSubTree(n));
    PrintTimeTestResult("Get double subtree", TestGetDoubleSubTree(n));
    PrintTimeTestResult("Get char subtree", TestGetCharSubTree(n));
    cout << endl;

    PrintTimeTestResult("Find int subtree", TestFindIntElementTree(n));
    PrintTimeTestResult("Find double subtree", TestFindDoubleElementTree(n));
    PrintTimeTestResult("Find char subtree", TestFindCharElementTree(n));
    cout << endl;

    PrintTimeTestResult("Balance int tree", TestBalanceIntTree(n));
    PrintTimeTestResult("Balance double tree", TestBalanceDoubleTree(n));
    PrintTimeTestResult("Balance char tree", TestBalanceCharTree(n));
    cout << endl;

    PrintTimeTestResult("Copy int tree", TestCloneIntTree(n));
    PrintTimeTestResult("Copy double tree", TestCloneDoubleTree(n));
    PrintTimeTestResult("Copy char tree", TestCloneCharTree(n));
    cout << endl;
}