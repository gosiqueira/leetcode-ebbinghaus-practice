// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::HashMap;
type Tnode = Option<Rc<RefCell<TreeNode>>>;
impl Solution {
    pub fn build_node(preorder: &[i32], tree: &[i32], inorder_map: &HashMap<i32, usize>) -> Tnode {
        if preorder.is_empty() || tree.is_empty() {return None};

        let root_val = preorder[0];
        let tree_start = inorder_map[&tree[0]];
        let root_i = inorder_map[&root_val] - tree_start;
        let mut val_node = TreeNode::new(root_val);

        let left_subtree = &tree[0..root_i];
        let right_subtree = &tree[root_i+1..tree.len()];

        val_node.left = Self::build_node(&preorder[1..], left_subtree, inorder_map);
        val_node.right = Self::build_node(&preorder[left_subtree.len()+1..], right_subtree, inorder_map);

        Some(Rc::new(RefCell::new(val_node)))
    }

    pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        let inorder_map: HashMap<i32, usize> = inorder.iter().enumerate().map(|(i, n)| (*n, i)).collect();
        Self::build_node(&preorder, &inorder, &inorder_map)
    }
}