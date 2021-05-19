from collections import List


def intersect(nums1: List[int], nums2: List[int]) -> List[int]:
    response = []
    for i in range(len(nums1)):
        for j in range(len(nums2)):
            if nums1[i] == nums2[j]:
                response.append(nums1[i])
                nums2[j] = -1
                break
                
    return response
