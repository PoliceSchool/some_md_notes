往红黑树里面插入节点，树的重排和重新着色教程，翻译自[这里](https://www.geeksforgeeks.org/red-black-tree-set-2-insert/)

# 说明

保持红黑树的平衡一共有两种方法：

1. 对树的重新着色
2. 旋转

我们先尝试重新着色，如果重新着色不生效，那么就转用旋转。下面是详细的算法。根据被插入节点的uncle节点的颜色，算法主要分为两种不同的情况。如果uncle节点是红色的，我们做重新着色。如果uncle节点是黑色的，我们做旋转或者重新着色或者两者都要做。NULL节点的颜色默认为黑色。

假设x是即将要插入的新节点

1. 执行标准的二叉搜索树插入操作，**并且令x的颜色为红色**。

2. 如果x是根节点，把x的颜色改为黑色（整棵树的black height递增至1）

3. 如果x的parent的颜色不是黑色 **并且** x不是根节点，执行下面的操作
   a) 若x的uncle节点是红色的（根据第4条特性，grant parent一定是黑的）
        (i)将x的parent和uncle的颜色都改为黑色
        (ii)将grant parent的颜色变为红色
        (iii)令 x = x的grand parent， 让新的x重复第2步和第3步
   ![redBlackCase2](../../images/data_structure/insert_rotation_1.png)

   b) 如果x的uncle节点是黑色的，那么对于x，x的parent(p)，x的grand parent(g)来说，一共有4种情况需要配置。
        (i)Left Left Case (p is left child of g and x is left child of p)
        (ii)Left Right Case (p is left child of g and x is right child of p)
        (iii)Right Right Case (Mirror of case i)
        (iv)Right Left Case (Mirror of case ii)
   下面4种操作对应上面4种情况**(其实可以看到，不论是4种中的哪一种情况，本质上都是红色节点下面有红色子节点，这一点违反了红黑树的第4个特性。之所以会出现红色节点下面又有红色子节点这些情况，其实与我们在第1步时将新插入的节点x的颜色设置为红色是脱不了干系的)**
   **Left Left Case (See g, p and x)**

   ![redBlackCase3a](../../images/data_structure/insert_rotation_2.png)
   **Left Right Case (See g, p and x)**
   ![redBlackCase3b](https://media.geeksforgeeks.org/wp-content/cdn-uploads/redBlackCase3b.png)
   **Right Right Case (See g, p and x)**
   ![redBlackCase3c](../../images/data_structure/insert_rotation_4.png)
   **Right Left Case (See g, p and x)**
   ![redBlackCase3d](../../images/data_structure/insert_rotation_5.png)

疑问：

1. 在第1步的时候为什么令x的颜色为红色？
2. 在第3步的时候如果x的parent的颜色是黑色的话为什么就不用重排或者重新着色了？换句话说当插入节点的parent节点是黑色时不用重排或者重新着色，树为什么也能保持平衡？

