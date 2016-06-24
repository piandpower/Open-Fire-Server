from framework import guid


def test_guid():
    ids = set()
    for _ in range(10000):
        new_id = guid()
        assert new_id not in ids
        ids.add(new_id)
