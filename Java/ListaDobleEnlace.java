public class ListaDobleEnlace<T>{
        /**
           * Clase de nodo, privada. Almacene el valor del nodo
           * Y la dirección del nodo anterior y del siguiente nodo
     */
    private class Node {
        T element;
        Node previous; // apunta al nodo anterior del nodo
        Node next; // apunta al siguiente nodo del nodo

        Node() {
        }

        // estructura
        Node(T element) {
            this.element = element;
        }
    }

    // registra el primer nodo
    private Node first;
    // registra el último nodo
    private Node last;
    // Registra el número de nodos en la lista vinculada
    private int count;


    /**
           * Obtenga el número de nodos en la lista vinculada
     *
           * @return el número de nodos
     */
    public int size() {
        return count;
    }

    /**
           * Obtenga el nodo correspondiente según el subíndice y regrese
     *
           * @param index necesita obtener el subíndice del nodo
           * @return el nodo correspondiente al subíndice
     */
    private Node getNode(int index) {
        // Obtener el valor del elemento según el índice
        if (index < 0 || index >= count) {
            // Si el subíndice está fuera de los límites, lanza una excepción
            throw new IndexOutOfBoundsException("Los subíndices de la lista deben estar en el rango: [0," + count + ") Entre");
        }
        // atravesar desde el primer nodo
        Node node = this.first;
        for (int i = 0; i < index; i++) {
            // Ir al nodo correspondiente al subíndice
            node = node.next;
        }
        // Devuelve el nodo atravesado
        return node;
    }

    /**
           * Eliminar un nodo
     *
           * @param node El nodo que se eliminará
     */
    private void removeNode(Node node) {
        if (count == 1) {
            // Si solo hay un nodo en esta lista vinculada
            // Luego borra la lista vinculada
            this.first = null;
            this.last = null;
            // Número de nodos -1
            count--;
            return;
        }
        if (node == this.first) {
            // Si necesita eliminar el primer nodo
            // Modifica el siguiente nodo del nodo al primero
            this.first = node.next;
            // Establecer el nodo anterior del siguiente nodo de nodo en nulo
            node.next.previous = null;
        } else if (node == this.last) {
            // Si necesita eliminar el último nodo
            // Modifica el último nodo del nodo al último
            this.last = node.previous;
            // Establecer el siguiente nodo del nodo anterior del nodo en nulo
            node.previous.next = null;
        } else {
            // elimina el nodo en el medio
            // Apunta el nodo anterior del siguiente nodo del nodo al nodo anterior del nodo
            node.next.previous = node.previous;
            // Apunte el siguiente nodo del nodo anterior del nodo al siguiente nodo del nodo
            node.previous.next = node.next;
        }
        // Eliminar todos los puntos del nodo
        node.previous = null;
        node.next = null;
        // Número de elementos -1
        count--;
    }

    /**
           * Agregar un nodo después de la lista vinculada
     *
           * @param element el valor del elemento del nuevo nodo
     */
    public void add(T element) {
        // crear una instancia de un objeto Node
        Node node = new Node(element);
        if (count == 0) {
            // Si no hay nodos en la lista vinculada
            // El nuevo elemento es el primero
            this.first = node;
        } else {
            // Si hay otros nodos en la lista vinculada
            // luego agregar al último elemento a su vez
            this.last.next = node;
            node.previous = this.last;
        }
        this.last = node;
        // Número de elementos +1
        count++;
    }

    /**
           * Agregar nodos según subíndice
     *
           * @param index Necesita agregar el subíndice del nodo
           * @param element el valor del nuevo nodo
     */
    public void add(int index, T element) {
        // crear una instancia de un nuevo nodo
        Node newNode = new Node(element);
        if (index == 0) {
            // agrega el primer nodo
            // Apunta a newNode junto al primer nodo original
            newNode.next = this.first;
            // Apunta el anterior del original primero a newNode
            this.first.previous = newNode;
            // Modifica el primer nodo a newNode
            this.first = newNode;
        } else if (index == count) {
            // agrega el último nodo
            // Apunta el siguiente del último original a newNode
            this.last.next = newNode;
            // Señala el nuevo nodo anterior al último original
            newNode.previous = this.last;
            // Modifica el último nodo a newNode
            this.last = newNode;
        } else {
            // Verifique el subíndice y obtenga el nodo correspondiente al subíndice
            Node node = getNode(index);
            // Modificación del nodo intermedio
            // El nodo anterior del nuevo nodo es el nodo anterior del nodo subíndice original
            newNode.previous = node.previous;
            // El siguiente nodo del nuevo nodo es el subíndice original.
            newNode.next = node;
            // Modificar el siguiente nodo del nodo anterior del nodo original como el nuevo nodo
            node.previous.next = newNode;
            // Modifica el nodo anterior del nodo original como un nuevo nodo
            node.previous = newNode;
        }
        // Número de elementos +1
        count++;
    }

    /**
           * Eliminar nodos según subíndice
     *
           * @param index Necesita eliminar el subíndice del nodo
           * @return valor eliminado correctamente
     */
    public T remove(int index) {
        // Verifica el subíndice y obtén el nodo
        Node node = getNode(index);
        // Eliminar nodo
        removeNode(node);
        // Devuelve el valor del nodo eliminado
        return node.element;
    }

    /**
           * Modificar el elemento especificado en la lista vinculada como el nuevo elemento
     *
           * @param index El subíndice que debe modificarse
           * @param elemento elemento modificado
           * @return el elemento antiguo antes de la modificación
     */
    public T set(int index, T element) {
        // Verifica el subíndice y obtén el nodo correspondiente del subíndice
        Node node = getNode(index);
        T oldElement = node.element;
        // Modificar el valor del elemento del nodo
        node.element = element;
        // Devuelve el elemento antiguo antes de la modificación
        return oldElement;
    }

    /**
           * Obtener el elemento del subíndice especificado en la lista vinculada
     *
           * @param index El subíndice que se debe obtener
           * @return devuelve el elemento especificado
     */
    public T get(int index) {
        // Verifica el subíndice y obtén el nodo correspondiente del subíndice
        Node node = getNode(index);
        // Obtiene el valor del elemento correspondiente al subíndice
        return node.element;
    }

    /**
           * Consultar el índice de la primera aparición de un elemento en la lista vinculada
     *
           * @param element El elemento que se va a consultar
           * @return la primera aparición del subíndice
     */
    public int indexOf(T element) {
        // Obtiene el primer nodo de la lista vinculada
        Node node = this.first;
        // Recorre los nodos de la lista enlazada y compara elementos
        for (int i = 0; i < size(); i++) {
            if (!element.equals(node.element)) {
            } else {
                // Devuelve la primera aparición del subíndice
                return i;
            }
            node = node.next;
        }
        // devuelve -1 si no se encuentra
        return -1;
    }

    /**
           * Determinar si el elemento especificado está contenido en la lista vinculada
     *
           * @param element El elemento a juzgar
           * @return resultado del juicio
     */
    public boolean contains(T element) {
        return indexOf(element) != -1;
    }


    /**
           * Eliminar el elemento especificado en la lista vinculada
     *
           * @param element El elemento a eliminar
     * @return se eliminó correctamente
     */
    public boolean remove(T element) {
        // Obtiene el primer nodo de la lista vinculada
        Node node = this.first;
        // Registra el número de elementos eliminados
        int removeCnt = 0;
        // Recorre los nodos de la lista enlazada y compara elementos
        for (int i = 0; i < size(); i++) {
            if (element.equals(node.element)) {
                // Elimina los elementos que cumplen los requisitos
                removeNode(node);
                // contador +1
                removeCnt++;
            }
            node = node.next;
        }
        return removeCnt != 0;
    }

    // Si solo elimina la primera aparición
    /*
    public boolean remove(T element) {
        int index = indexOf(element);
        if (index == -1) {
            return false;
        }
        remove(index);
        return true;
    }
    */

    /**
           * Borrar todos los datos en la lista vinculada
     */
    public void clear() {
        this.first = null;
        this.last = null;
        count = 0;
    }


    @Override
    public String toString() {
        // crear una instancia de un objeto StringBuilder
        if (count == 0) {
            // Si la lista vinculada está vacía, regrese directamente []
            return "[]";
        }
        StringBuilder sb = new StringBuilder("[ ");
        // comienza a hacer un bucle desde el primer nodo
        Node node = this.first;
        for (int i = 0; i < size(); i++) {
            // Adjuntar a StringBuilder
            sb.append(node.element).append(" , ");
            node = node.next;
        }
        sb.replace(sb.length() - 3, sb.length(), " ]");
        return sb.toString();
    }
}