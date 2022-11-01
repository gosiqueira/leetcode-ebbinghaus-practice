// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        fn add_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, carry: i32) -> Option<Box<ListNode>> {
            if l1.is_none() && l2.is_none() && carry == 0 {
                return None;
            }

            let mut val = carry;
            val += l1.as_ref().map(|l| l.val).unwrap_or(0);
            val += l2.as_ref().map(|l| l.val).unwrap_or(0);

            let mut result = ListNode::new(val%10);

            if l1.is_some() || l2.is_some() {
                let nxt = add_lists(
                    l1.and_then(|l| l.next),
                    l2.and_then(|l| l.next),
                    if val > 9 {1} else {0}
                );

                result.next = nxt;
            }

            Some(Box::new(result))
        }

        add_lists(l1, l2, 0)
    }
}