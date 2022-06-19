namespace my_lib {
	class Box
	{
	public:
		/* construct the Box with default size (1,1,1) */
		Box();
		/*Constructs an Box with the give length, height & width*/
		Box(int length, int height, int width);

		//Accessor : Getters
		int getHeight() const;
		int getWidth() const;
		int getLength() const;

		Box* setLength(int length);
		Box* setWidth(int width);
		Box* setHeight(int height);


		Box& set_length(int length);
		Box& set_width(int width);
		Box& set_height(int height);

	private:
		int length;
		int width;
		int height;
		bool isHeightValid(int height) const;
		bool isWidthValid(int height) const;
		bool isLengthValid(int height) const;
		bool checkDimensions(int length, int height, int width) const;
	};
}