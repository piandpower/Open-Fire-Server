class Base:
    RID = 'rid'

    def __init__(self):
        self.rid = None

    @classmethod
    def create_class(cls):
        raise NotImplementedError

    def save(self):
        raise NotImplementedError

    @classmethod
    def read(cls):
        raise NotImplementedError

    def _generate_proerty_keys_string(self):
        keys_without_rid = []
        for key, value in self.__generate_properties_without_rid().items():
            keys_without_rid.append(key)

        keys_string = ", ".join(keys_without_rid)
        return keys_string

    def _generate_property_values_string(self):
        values_without_rid = []
        for key, value in self.__generate_properties_without_rid().items():
            values_without_rid.append(value)

        values_string = ", ".join(values_without_rid)
        return values_string

    def _generate_update_string(self):
        update_strings = []
        for key, value in self.__generate_properties_without_rid().items():
            update_strings.append('SET ' + key + ' = ' + value)

        return " ".join(update_strings)

    def __generate_properties_without_rid(self):
        properties = {}
        for key, value in self.__dict__.items():
            if key is not self.RID:
                properties[key] = str(value)

        return properties
