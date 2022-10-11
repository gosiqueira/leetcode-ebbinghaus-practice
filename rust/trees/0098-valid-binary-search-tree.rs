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
    fn inorder(root: Option<Rc<RefCell<TreeNode>>>, prev: &mut Option<i32>) -> bool {
        if root.is_none() {return true};
        let root = root.unwrap();
        let root = root.borrow();
        
        let left_valid = Self::inorder(root.left.clone(), prev);

        if let Some(prev_val) = prev {
            if *prev_val >= root.val {return false};
        }
        *prev = Some(root.val);

        let right_valid = Self::inorder(root.right.clone(), prev);

        left_valid && right_valid
    }

    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        let mut prev = None;
        Self::inorder(root, &mut prev)
    }
}