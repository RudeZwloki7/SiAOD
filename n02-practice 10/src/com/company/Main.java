package com.company;

import java.util.Scanner;

public class Main {
    public static BinaryTree createBinaryTree(int[] array) {
        BinaryTree bt = new BinaryTree();

        for (int i : array) {
            bt.add(i);
        }

        return bt;
    }

    public static AVLTree createAVLTree(int[] array) {
        AVLTree bt = new AVLTree();

        for (int i : array) {
            bt.insert(i);
        }

        return bt;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();
        int[] arr = new int[length];
        for (int i =0; i< length; i++){
            arr[i] = sc.nextInt();
        }

        BinaryTree tree = createBinaryTree(arr);//17 40 27 50 99 73 16
        tree.printTree();
        System.out.println("===============================");

        AVLTree avlTree = createAVLTree(arr);
        avlTree.printAVLTree();


    }
}
