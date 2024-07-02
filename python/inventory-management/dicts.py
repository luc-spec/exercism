"""Functions to keep track and alter inventory."""
def create_inventory(items: list) -> dict:
    """Create a dict that tracks the amount (count) of each element on the `items` list.

    :param items: list - list of items to create an inventory from.
    :return: inventory - the inventory dictionary in the form { item:count }
    """
    inventory = {}
    add_items(inventory, items)
    return inventory

def modify_items(inventory: dict, items: list, increment: int) -> dict:
    """Create central logic for add_items and decrement_items; any items that do
    not exist will be created with count equal to increment.

    :param inventory: dict - dictionary of existing inventory
    :param items: list - list of items to update the inventory with.
    :param increment: int - the value by which the inventory should change for **every** item in items
    :return: dict - the inventory updated with the new items.
    """
    for item in items:
        if item in inventory.keys():
            inventory[item] = inventory[item] + increment
            if inventory[item] < 0:
                inventory[item] = 0
        elif item not in inventory.keys() and increment > 0:
            inventory[item] = increment
        elif item not in inventory.keys() and increment < 0:
            pass

    return inventory


def add_items(inventory: dict, items: list) -> dict:
    """Add or increment items in inventory using elements from the items `list`.

    :param inventory: dict - dictionary of existing inventory.
    :param items: list - list of items to update the inventory with.
    :return: dict - the inventory updated with the new items.
    """
    inventory = modify_items(inventory, items, +1)
    return inventory

def decrement_items(inventory: dict, items: list):
    """Decrement items in inventory using elements from the `items` list.

    :param inventory: dict - inventory dictionary.
    :param items: list - list of items to decrement from the inventory.
    :return: dict - updated inventory with items decremented.
    """
    inventory = modify_items(inventory, items, -1)
    return inventory

def remove_item(inventory: dict, item: str):
    """Remove item from inventory if it matches `item` string.

    :param inventory: dict - inventory dictionary.
    :param item: str - item to remove from the inventory.
    :return: dict - updated inventory with item removed. Current inventory if item does not match.
    """
    if item in inventory.keys():
        inventory.pop(item)
    else:
        print(f"INFO: Requested to pop {item}, which was not present in the inventory. Skipping.") 
    return inventory

def list_inventory(inventory_dict: dict):
    """Create a list containing only available (item_name, item_count > 0) pairs in inventory.

    :param inventory: dict - an inventory dictionary.
    :return: list of tuples - list of key, value pairs from the inventory dictionary.
    """
    inventory_list = []
    for key, val in inventory_dict.items():
        if val > 0:
            inventory_list.append((key,val))
    return inventory_list

