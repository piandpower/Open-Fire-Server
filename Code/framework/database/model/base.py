class Base:
    name = None

    @classmethod
    def create_class(cls):
        raise NotImplementedError
