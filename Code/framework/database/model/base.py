class Base:
    name = None

    @classmethod
    def create_class(cls):
        raise NotImplementedError

    def save(self):
        raise NotImplementedError

    @classmethod
    def read(cls):
        raise NotImplementedError
