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
impl Solution {
    fn to_tree(tree: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if tree.is_empty() {return None};

        let mid = tree.len()/2;
        let val = tree[mid];
        let mut root = TreeNode::new(val);

        root.left = Self::to_tree(&tree[0..mid]);
        root.right = Self::to_tree(&tree[mid+1..tree.len()]);

        Some(Rc::new(RefCell::new(root)))
    }

    pub fn sorted_array_to_bst(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::to_tree(&nums)
    }
}