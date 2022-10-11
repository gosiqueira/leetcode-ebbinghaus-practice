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
use std::collections::VecDeque;
impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        if root.is_none() {return vec![]};

        let mut levels = vec![];
        let mut to_visit = VecDeque::from([(root.unwrap(), 0)]);
        while let Some((node, level)) = to_visit.pop_front() {
            let mut node = node.borrow_mut();

            if level >= levels.len() {
                levels.push(vec![node.val]);
            } else {
                levels[level].push(node.val);
            }

            for child in [node.left.take(), node.right.take()] {
                if child.is_none() {continue};

                to_visit.push_back((child.unwrap(), level+1));
            }
        }

        levels
    }
}